#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "qtextcursor.h"
#include <QTextCursor>
#include <QWidget>

namespace Ui {
class TextEdit;
}

class TextEdit : public QWidget
{
    Q_OBJECT

public:
    bool changed = false;
    explicit TextEdit(QWidget *parent = nullptr);
    void setText(QString text);
    QTextCursor textCursor();
    void setTextCursor(QTextCursor cursor);
    QTextDocument* document();
    QString toPlainText();
    void copy();
    void paste();
    void cut();
    void undo();
    void redo();
    ~TextEdit();

private slots:
    void textEditHScrollBarChanged();
    void textEditVScrollBarChanged();
    void textBrowserVScrollBarChanged();
    void scrollBarChanged();
    void onTextChanged();
    void highlightCurLine();

private:
    Ui::TextEdit *ui;
    void initConnect();
    void initFont();
    void initHighlight();
};

#endif // TEXTEDIT_H
