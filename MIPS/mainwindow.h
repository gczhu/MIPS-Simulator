#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    int count = 0;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event);

private slots:
    void on_new_file_triggered();

    void on_open_file_triggered();

    void on_save_file_triggered();

    void on_save_as_triggered();

    void on_copy_triggered();

    void on_paste_triggered();

    void on_cut_triggered();

    void on_about_triggered();

    void on_undo_triggered();

    void on_redo_triggered();

    void on_exit_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void changeTab();

    void on_execute_triggered();

    void on_assemble_triggered();

    void on_disassemble_triggered();

    void on_convert_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile;
};

#endif // MAINWINDOW_H
