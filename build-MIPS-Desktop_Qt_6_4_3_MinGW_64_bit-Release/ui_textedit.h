/********************************************************************************
** Form generated from reading UI file 'textedit.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDIT_H
#define UI_TEXTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextEdit
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QScrollBar *horizontalScrollBar;

    void setupUi(QWidget *TextEdit)
    {
        if (TextEdit->objectName().isEmpty())
            TextEdit->setObjectName("TextEdit");
        TextEdit->resize(638, 366);
        verticalLayout = new QVBoxLayout(TextEdit);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        textBrowser = new QTextBrowser(TextEdit);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMaximumSize(QSize(44, 16777215));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(textBrowser);

        textEdit = new QTextEdit(TextEdit);
        textEdit->setObjectName("textEdit");
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);

        horizontalLayout->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalScrollBar = new QScrollBar(TextEdit);
        horizontalScrollBar->setObjectName("horizontalScrollBar");
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar);


        retranslateUi(TextEdit);

        QMetaObject::connectSlotsByName(TextEdit);
    } // setupUi

    void retranslateUi(QWidget *TextEdit)
    {
        TextEdit->setWindowTitle(QCoreApplication::translate("TextEdit", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextEdit: public Ui_TextEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDIT_H
