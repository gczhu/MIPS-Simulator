#ifndef CONVERTWINDOW_H
#define CONVERTWINDOW_H

#include <QButtonGroup>
#include <QWidget>

namespace Ui {
class ConvertWindow;
}

class ConvertWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ConvertWindow(QWidget *parent = nullptr);
    ~ConvertWindow();
    QButtonGroup option;
    int choice = 1;

public slots:
    void on_button_clicked();
    void on_option_changed();


private:
    Ui::ConvertWindow *ui;
    void init();
};

#endif // CONVERTWINDOW_H
