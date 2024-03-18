/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *new_file;
    QAction *open_file;
    QAction *save_file;
    QAction *save_as;
    QAction *copy;
    QAction *paste;
    QAction *cut;
    QAction *about;
    QAction *undo;
    QAction *redo;
    QAction *exit;
    QAction *execute;
    QAction *assemble;
    QAction *disassemble;
    QAction *convert;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QToolBar *toolBar_4;
    QToolBar *toolBar_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/windowIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        new_file = new QAction(MainWindow);
        new_file->setObjectName("new_file");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        new_file->setIcon(icon1);
        open_file = new QAction(MainWindow);
        open_file->setObjectName("open_file");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        open_file->setIcon(icon2);
        save_file = new QAction(MainWindow);
        save_file->setObjectName("save_file");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_file->setIcon(icon3);
        save_as = new QAction(MainWindow);
        save_as->setObjectName("save_as");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_as->setIcon(icon4);
        copy = new QAction(MainWindow);
        copy->setObjectName("copy");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copy->setIcon(icon5);
        paste = new QAction(MainWindow);
        paste->setObjectName("paste");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        paste->setIcon(icon6);
        cut = new QAction(MainWindow);
        cut->setObjectName("cut");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        cut->setIcon(icon7);
        about = new QAction(MainWindow);
        about->setObjectName("about");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        about->setIcon(icon8);
        undo = new QAction(MainWindow);
        undo->setObjectName("undo");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/edit_undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undo->setIcon(icon9);
        redo = new QAction(MainWindow);
        redo->setObjectName("redo");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/images/edit_redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        redo->setIcon(icon10);
        exit = new QAction(MainWindow);
        exit->setObjectName("exit");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit->setIcon(icon11);
        execute = new QAction(MainWindow);
        execute->setObjectName("execute");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/images/execute.png"), QSize(), QIcon::Normal, QIcon::Off);
        execute->setIcon(icon12);
        assemble = new QAction(MainWindow);
        assemble->setObjectName("assemble");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/images/assemble.png"), QSize(), QIcon::Normal, QIcon::Off);
        assemble->setIcon(icon13);
        disassemble = new QAction(MainWindow);
        disassemble->setObjectName("disassemble");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/images/disassemble.png"), QSize(), QIcon::Normal, QIcon::Off);
        disassemble->setIcon(icon14);
        convert = new QAction(MainWindow);
        convert->setObjectName("convert");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/images/convert.png"), QSize(), QIcon::Normal, QIcon::Off);
        convert->setIcon(icon15);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(440, 80, 104, 64));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 0, 120, 80));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideMiddle);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName("toolBar_2");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName("toolBar_3");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);
        toolBar_4 = new QToolBar(MainWindow);
        toolBar_4->setObjectName("toolBar_4");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_4);
        toolBar_5 = new QToolBar(MainWindow);
        toolBar_5->setObjectName("toolBar_5");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_5);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(new_file);
        menu->addAction(open_file);
        menu->addSeparator();
        menu->addAction(save_file);
        menu->addAction(save_as);
        menu->addSeparator();
        menu->addAction(exit);
        menu_2->addAction(copy);
        menu_2->addAction(paste);
        menu_2->addAction(cut);
        menu_2->addSeparator();
        menu_2->addAction(undo);
        menu_2->addAction(redo);
        menu_3->addAction(about);
        menu_4->addAction(assemble);
        menu_4->addAction(disassemble);
        menu_4->addAction(execute);
        menu_4->addAction(convert);
        toolBar->addAction(new_file);
        toolBar->addAction(open_file);
        toolBar->addAction(save_file);
        toolBar->addAction(save_as);
        toolBar_2->addAction(copy);
        toolBar_2->addAction(paste);
        toolBar_2->addAction(cut);
        toolBar_3->addAction(assemble);
        toolBar_3->addAction(disassemble);
        toolBar_3->addAction(execute);
        toolBar_3->addAction(convert);
        toolBar_4->addAction(undo);
        toolBar_4->addAction(redo);
        toolBar_5->addAction(about);
        toolBar_5->addAction(exit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MIPS Simulator", nullptr));
        new_file->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        new_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        open_file->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        open_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        save_file->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        save_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        save_as->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272...", nullptr));
#if QT_CONFIG(shortcut)
        save_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        copy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        copy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        paste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        paste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        cut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        cut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        about->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(shortcut)
        about->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+A", nullptr));
#endif // QT_CONFIG(shortcut)
        undo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\345\233\236", nullptr));
#if QT_CONFIG(shortcut)
        undo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        redo->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232", nullptr));
#if QT_CONFIG(shortcut)
        redo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        exit->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        execute->setText(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214\350\207\263\345\205\211\346\240\207", nullptr));
#if QT_CONFIG(shortcut)
        execute->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        assemble->setText(QCoreApplication::translate("MainWindow", "\346\261\207\347\274\226", nullptr));
#if QT_CONFIG(shortcut)
        assemble->setShortcut(QCoreApplication::translate("MainWindow", "Alt+R", nullptr));
#endif // QT_CONFIG(shortcut)
        disassemble->setText(QCoreApplication::translate("MainWindow", "\345\217\215\346\261\207\347\274\226", nullptr));
#if QT_CONFIG(shortcut)
        disassemble->setShortcut(QCoreApplication::translate("MainWindow", "Alt+Shift+R", nullptr));
#endif // QT_CONFIG(shortcut)
        convert->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242", nullptr));
#if QT_CONFIG(shortcut)
        convert->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
        toolBar_3->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_3", nullptr));
        toolBar_4->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_4", nullptr));
        toolBar_5->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
