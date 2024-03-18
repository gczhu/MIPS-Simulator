#include "mainwindow.h"
#include "convertwindow.h"
#include "qtextobject.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include "textedit.h"
#include "method.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tabWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    for (int i = 0; i < ui->tabWidget->count(); i++) {
        QString tabName = ui->tabWidget->tabText(i);
        ui->tabWidget->setCurrentIndex(i);
        TextEdit* textEdit = (TextEdit*)ui->tabWidget->widget(i);
        if(textEdit->changed){
            QMessageBox::StandardButton btn = QMessageBox::question(this, "警告", "是否保存文件：" + tabName, QMessageBox::Yes|QMessageBox::No);
            if(btn == QMessageBox::Yes){
                on_save_file_triggered();
            }
        }
    }
}


void MainWindow::on_new_file_triggered()
{
    TextEdit* textEdit = new TextEdit(this);
    ui->tabWidget->addTab(textEdit, "Untitled" + QString::number(++count));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}


void MainWindow::on_open_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(this, "警告", "无法打开文件：" + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    TextEdit* textEdit = new TextEdit(this);
    ui->tabWidget->addTab(textEdit, fileName);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    textEdit->setText(text);
    textEdit->changed = false;
    ui->tabWidget->setTabText(ui->tabWidget->count() - 1, fileName);
    file.close();
}


void MainWindow::on_save_file_triggered()
{
    QString fileName;
    int idx = ui->tabWidget->currentIndex();
    QString checkName = ui->tabWidget->tabText(idx).mid(0, 8);
    if(currentFile.isEmpty() || checkName == "Untitled"){
        fileName = QFileDialog::getSaveFileName(this, "保存文件");
        currentFile = fileName;
    }else{
        fileName = ui->tabWidget->tabText(idx);
        if(fileName[fileName.length() - 1] == '*'){
            fileName.chop(1);
        }
    }
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text)){
        QMessageBox::warning(this, "警告", "无法保存文件：" + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
    if(textEdit){
        out << textEdit->toPlainText();
    }
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), fileName);
    textEdit->changed = false;
    file.close();
}


void MainWindow::on_save_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "另存文件");
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text)){
        QMessageBox::warning(this, "警告", "无法保存文件：" + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
    if(textEdit){
        out << textEdit->toPlainText();
    }
    textEdit->changed = false;
    file.close();
}


void MainWindow::on_copy_triggered()
{
    TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
    if(textEdit){
        textEdit->copy();
    }
}


void MainWindow::on_paste_triggered()
{
    TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
    if(textEdit){
        textEdit->paste();
    }
}


void MainWindow::on_cut_triggered()
{
    TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
    if(textEdit){
        textEdit->cut();
    }
}


void MainWindow::on_about_triggered()
{
    QMessageBox::about(this, "MIPS模拟器说明文档", "该项目实现了一个MIPS模拟器\n主要功能模块：汇编、反汇编、运行至光标、转换/运算\n"
                       "支持汇编的指令：add addi sll srl mult sub div and andi or ori xor xori nor beq bne slt jr jal j\n"
                       "支持反汇编和执行的指令：add addi lw sw nor sll srl beq bne slt jr jal\n");
}


void MainWindow::on_undo_triggered()
{
    TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
    if(textEdit){
        textEdit->undo();
    }
}


void MainWindow::on_redo_triggered()
{
    TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
    if(textEdit){
        textEdit->redo();
    }
}


void MainWindow::on_exit_triggered()
{
    for (int i = 0; i < ui->tabWidget->count(); i++) {
        QString tabName = ui->tabWidget->tabText(i);
        ui->tabWidget->setCurrentIndex(i);
        TextEdit* textEdit = (TextEdit*)ui->tabWidget->widget(i);
        if(textEdit->changed){
            QMessageBox::StandardButton btn = QMessageBox::question(this, "警告", "是否保存文件：" + tabName, QMessageBox::Yes|QMessageBox::No);
            if(btn == QMessageBox::Yes){
                on_save_file_triggered();
            }
        }
    }
    QCoreApplication::exit();
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->setCurrentIndex(index);
    QString tabName = ui->tabWidget->tabText(index);
    TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
    if(textEdit->changed){
        QMessageBox::StandardButton btn = QMessageBox::question(this, "警告", "是否保存文件：" + tabName, QMessageBox::Yes|QMessageBox::No);
        if(btn == QMessageBox::Yes){
            on_save_file_triggered();
        }
    }
    ui->tabWidget->removeTab(index);
}

void MainWindow::changeTab()
{
    int idx = ui->tabWidget->currentIndex();
    QString tabName = ui->tabWidget->tabText(idx);
    int last = tabName.length() - 1;
    TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
    if(tabName[last] != '*' && textEdit->changed){
        ui->tabWidget->setTabText(idx, tabName + "*");
    }
}


void MainWindow::on_execute_triggered()
{
    // 获取文件名
    int idx = ui->tabWidget->currentIndex();
    // 若没有打开文件，则不执行
    if(idx < 0){
        QMessageBox::information(this, "提示", "执行失败：\n请先打开文件", QMessageBox::Ok);
    }else{
        // 保存文件
        on_save_file_triggered();
        QString fileName = ui->tabWidget->tabText(idx);
        // 得到其生成的结果文件名
        int idx_postfix;
        for (int i = fileName.length() - 1; i >= 0; i--) {
            if(fileName[i] == '.'){
                idx_postfix = i;
                break;
            }
        }
        if(idx_postfix > 0){
            fileName.chop(fileName.length() - idx_postfix);
        }
        fileName += ".o";
        // 获取光标所在行之上的所有代码
        Method* method = new Method();
        TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
        QString str = "";
        QTextCursor cursor = textEdit->textCursor();
        int line = cursor.blockNumber();
        QTextBlock textBlock = textEdit->document()->findBlockByLineNumber(line);
        str += textBlock.text() + "\n";
        // 执行代码
        int pc = method->execute(str.toStdString(), fileName.toStdString(), line);
        if(pc == -1){
            QMessageBox::information(this, "提示", "执行失败：\n请检查二进制代码是否存在", QMessageBox::Ok);
        }
        // 光标自动下移一行
        textBlock = textEdit->document()->findBlockByLineNumber(pc);
        textEdit->setTextCursor(QTextCursor(textBlock));
    }
}


void MainWindow::on_assemble_triggered()
{
    // 获取文件名
    int idx = ui->tabWidget->currentIndex();
    // 若没有打开文件，则不进行汇编
    if(idx < 0){
        QMessageBox::information(this, "提示", "汇编失败：\n请先打开汇编文件", QMessageBox::Ok);
    }else{
        // 保存文件
        on_save_file_triggered();
        QString fileName = ui->tabWidget->tabText(idx);
        // 得到其生成的二进制文件名
        int idx_postfix;
        for (int i = fileName.length() - 1; i >= 0; i--) {
            if(fileName[i] == '.'){
                idx_postfix = i;
                break;
            }
        }
        if(idx_postfix > 0){
            fileName.chop(fileName.length() - idx_postfix);
        }
        fileName += ".bin";
        // 汇编文件，并将结果写入二进制文件中
        Method* method = new Method();
        TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
        QString str = textEdit->toPlainText();
        if(method->assemble(str.toStdString(), fileName.toStdString())){
            QMessageBox::information(this, "提示", "汇编成功：\n请到 " + fileName + " 文件中查看汇编结果", QMessageBox::Ok);
        }else{
            QMessageBox::information(this, "提示", "汇编失败：\n请检查汇编代码格式", QMessageBox::Ok);
        }
    }
}


void MainWindow::on_disassemble_triggered()
{
    // 获取文件名
    int idx = ui->tabWidget->currentIndex();
    if(idx < 0){        // 若没有打开文件，则不进行反汇编
        QMessageBox::information(this, "提示", "反汇编失败：\n请先打开二进制文件", QMessageBox::Ok);
    }else{
        // 保存文件
        on_save_file_triggered();
        QString fileName = ui->tabWidget->tabText(idx);
        // 得到其生成的汇编文件名
        int idx_postfix;
        for (int i = fileName.length() - 1; i >= 0; i--) {
            if(fileName[i] == '.'){
                idx_postfix = i;
                break;
            }
        }
        if(idx_postfix > 0){
            fileName.chop(fileName.length() - idx_postfix);
        }
        fileName += ".asm";
        // 汇编文件，并将结果写入二进制文件中
        Method* method = new Method();
        TextEdit* textEdit = (TextEdit*)ui->tabWidget->currentWidget();
        QString str = textEdit->toPlainText();
        if(method->disassemble(str.toStdString(), fileName.toStdString())){
            QMessageBox::information(this, "提示", "反汇编成功：\n请到 " + fileName + " 文件中查看反汇编结果", QMessageBox::Ok);
        }else{
            QMessageBox::information(this, "提示", "反汇编失败：\n请检查二进制代码格式", QMessageBox::Ok);
        }
    }
}


void MainWindow::on_convert_triggered()
{
    ConvertWindow* convertWindow =  new ConvertWindow;
    convertWindow->show();
}

