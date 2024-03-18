#include "highlight.h"
#include "textedit.h"
#include "ui_textedit.h"
#include "mainwindow.h"

TextEdit::TextEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextEdit)
{
    ui->setupUi(this);
    // 初始行号设为1并设置行号右对齐
    ui->textBrowser->setText("1\n");
    QTextBlockFormat format;
    format.setAlignment(Qt::AlignRight);
    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(format);
    // 初始化连接
    initConnect();
    // 将textEdit是否改变与tabWidget绑定
    connect(ui->textEdit, SIGNAL(textChanged()), parent, SLOT(changeTab()));
    // 初始化字体
    initFont();
    // 初始化代码高亮
    initHighlight();
    // 当前行高亮
    highlightCurLine();
}

void TextEdit::setText(QString text)
{
    ui->textEdit->setText(text);
}

QTextCursor TextEdit::textCursor()
{
    return ui->textEdit->textCursor();
}

void TextEdit::setTextCursor(QTextCursor cursor)
{
    ui->textEdit->setTextCursor(cursor);
}

QTextDocument *TextEdit::document()
{
    return ui->textEdit->document();
}

QString TextEdit::toPlainText()
{
    return ui->textEdit->toPlainText();
}

void TextEdit::copy()
{
    ui->textEdit->copy();
}

void TextEdit::paste()
{
    ui->textEdit->paste();
}

void TextEdit::cut()
{
    ui->textEdit->cut();
}

void TextEdit::undo()
{
    ui->textEdit->undo();
}

void TextEdit::redo()
{
    ui->textEdit->redo();
}

TextEdit::~TextEdit()
{
    delete ui;
}

void TextEdit::initConnect()
{
    // 将textEdit中文本的行数与左侧textBrowser的行号绑定
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(onTextChanged()));

    // 将textEdit的水平滚条与ui的水平滚动条绑定
    connect(ui->textEdit->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(textEditHScrollBarChanged()));
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(scrollBarChanged()));

    // 将textEdit垂直滚条与textBrowser的行号绑定
    connect(ui->textEdit->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(textEditVScrollBarChanged()));
    connect(ui->textBrowser->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(textBrowserVScrollBarChanged()));

    // 将光标与当前行高亮绑定
    connect(ui->textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurLine()));
}

void TextEdit::initFont()
{
    QFont font("Consolas", 14);
    ui->textEdit->setFont(font);
    ui->textBrowser->setFont(font);
}

void TextEdit::initHighlight()
{
    new Highlight(ui->textEdit->document());
}

void TextEdit::highlightCurLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;
    selection.format.setBackground(QColor(0, 100, 100, 20));
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = ui->textEdit->textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);
    ui->textEdit->setExtraSelections(extraSelections);
}

void TextEdit::textEditHScrollBarChanged()
{
    ui->horizontalScrollBar->setMaximum(ui->textEdit->horizontalScrollBar()->maximum());
    ui->horizontalScrollBar->setMinimum(ui->textEdit->horizontalScrollBar()->minimum());
    ui->horizontalScrollBar->setPageStep(ui->textEdit->horizontalScrollBar()->pageStep());
    ui->horizontalScrollBar->setValue(ui->textEdit->horizontalScrollBar()->value());
}

void TextEdit::textEditVScrollBarChanged()
{
    ui->textBrowser->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->value());
}

void TextEdit::textBrowserVScrollBarChanged()
{
    ui->textEdit->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->value());
}

void TextEdit::scrollBarChanged()
{
    ui->textEdit->horizontalScrollBar()->setValue(ui->horizontalScrollBar->value());
}

void TextEdit::onTextChanged()
{
    changed = true;
    // 获取行数lineCount，并将1-lineCount依次存放在字符串中
    int editLineCount = ui->textEdit->document()->lineCount();
    QString text = ui->textBrowser->toPlainText();
    int browserLineCount = text.trimmed().split("\n").length();

    if(browserLineCount < editLineCount){
        for (int i = browserLineCount; i < editLineCount; i++) {
            text += QString::number(i+1) + "\n";
        }
    } else if(browserLineCount > editLineCount) {
        for (int i = browserLineCount; i > editLineCount; i--) {
            text.chop((QString::number(i) + "\n").length());
        }
    } else if(browserLineCount == 1 && text.length() < 1){
        text += "1\n";
    }

    // 设置textBrowser的最大宽度实现界面自适应
    int maxWidth = 44;
    if(maxWidth < 14 + QString::number(browserLineCount).length() * 10){
        maxWidth = 14 + QString::number(browserLineCount).length() * 10;
    }
    ui->textBrowser->setMaximumWidth(maxWidth);
    ui->textBrowser->setText(text);

    // 设置行号右对齐
    QFont font("Consolas", 14);
    QTextBlockFormat format;
    format.setAlignment(Qt::AlignRight);
    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(format);
}
