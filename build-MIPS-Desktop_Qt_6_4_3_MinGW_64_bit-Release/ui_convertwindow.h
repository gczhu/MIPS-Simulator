/********************************************************************************
** Form generated from reading UI file 'convertwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTWINDOW_H
#define UI_CONVERTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvertWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_input;
    QLineEdit *inputText;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QPushButton *startButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_output;
    QLineEdit *outputText;

    void setupUi(QWidget *ConvertWindow)
    {
        if (ConvertWindow->objectName().isEmpty())
            ConvertWindow->setObjectName("ConvertWindow");
        ConvertWindow->resize(400, 200);
        ConvertWindow->setMaximumSize(QSize(400, 200));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/convert.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConvertWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(ConvertWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label_input = new QLabel(ConvertWindow);
        label_input->setObjectName("label_input");

        horizontalLayout->addWidget(label_input);

        inputText = new QLineEdit(ConvertWindow);
        inputText->setObjectName("inputText");

        horizontalLayout->addWidget(inputText);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        radioButton_1 = new QRadioButton(ConvertWindow);
        radioButton_1->setObjectName("radioButton_1");

        horizontalLayout_3->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(ConvertWindow);
        radioButton_2->setObjectName("radioButton_2");

        horizontalLayout_3->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(ConvertWindow);
        radioButton_3->setObjectName("radioButton_3");

        horizontalLayout_3->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(ConvertWindow);
        radioButton_4->setObjectName("radioButton_4");

        horizontalLayout_3->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(ConvertWindow);
        radioButton_5->setObjectName("radioButton_5");

        horizontalLayout_3->addWidget(radioButton_5);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        startButton = new QPushButton(ConvertWindow);
        startButton->setObjectName("startButton");

        gridLayout->addWidget(startButton, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_output = new QLabel(ConvertWindow);
        label_output->setObjectName("label_output");

        horizontalLayout_2->addWidget(label_output);

        outputText = new QLineEdit(ConvertWindow);
        outputText->setObjectName("outputText");

        horizontalLayout_2->addWidget(outputText);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);


        retranslateUi(ConvertWindow);

        QMetaObject::connectSlotsByName(ConvertWindow);
    } // setupUi

    void retranslateUi(QWidget *ConvertWindow)
    {
        ConvertWindow->setWindowTitle(QCoreApplication::translate("ConvertWindow", "\350\275\254\346\215\242", nullptr));
        label_input->setText(QCoreApplication::translate("ConvertWindow", "\350\276\223\345\205\245", nullptr));
        radioButton_1->setText(QCoreApplication::translate("ConvertWindow", "\346\225\264\346\225\260->\350\241\245\347\240\201", nullptr));
        radioButton_2->setText(QCoreApplication::translate("ConvertWindow", "\350\241\245\347\240\201->\346\225\264\346\225\260", nullptr));
        radioButton_3->setText(QCoreApplication::translate("ConvertWindow", "\346\265\256\347\202\271\346\225\260->\344\272\214\350\277\233\345\210\266", nullptr));
        radioButton_4->setText(QCoreApplication::translate("ConvertWindow", "\344\272\214\350\277\233\345\210\266->\346\265\256\347\202\271\346\225\260", nullptr));
        radioButton_5->setText(QCoreApplication::translate("ConvertWindow", "\350\256\241\347\256\227\350\241\250\350\276\276\345\274\217", nullptr));
        startButton->setText(QCoreApplication::translate("ConvertWindow", "\345\274\200\345\247\213\350\275\254\346\215\242/\350\256\241\347\256\227", nullptr));
        label_output->setText(QCoreApplication::translate("ConvertWindow", "\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvertWindow: public Ui_ConvertWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTWINDOW_H
