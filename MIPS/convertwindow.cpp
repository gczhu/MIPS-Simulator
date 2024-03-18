#include "convertwindow.h"
#include "convertwindow.h"
#include "ui_convertwindow.h"
#include "method.h"


ConvertWindow::ConvertWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConvertWindow)
{
    ui->setupUi(this);
    init();
}

ConvertWindow::~ConvertWindow()
{
    delete ui;
}

void ConvertWindow::on_button_clicked()
{
    QString input = ui->inputText->text();
    Method* method = new Method();
    string output = method->convert(input.toStdString(), choice);
    ui->outputText->setText(QString::fromStdString(output));
}

void ConvertWindow::on_option_changed()
{
    // 当button被点击时改变choice的值
    choice = option.checkedId();
}

void ConvertWindow::init()
{
    // init button
    option.addButton(ui->radioButton_1, 1);
    option.addButton(ui->radioButton_2, 2);
    option.addButton(ui->radioButton_3, 3);
    option.addButton(ui->radioButton_4, 4);
    option.addButton(ui->radioButton_5, 5);
    ui->radioButton_1->setChecked(true);
    // init connect
    connect(&option, SIGNAL(idToggled(int,bool)), this, SLOT(on_option_changed()));
    connect(ui->startButton, &QPushButton::clicked, this, &ConvertWindow::on_button_clicked);
}
