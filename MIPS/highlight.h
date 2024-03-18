#ifndef HIGHLIGHT_H
#define HIGHLIGHT_H

#include <QObject>
#include <QSyntaxHighlighter>
#include <QRegularExpression>

class Highlight : public QSyntaxHighlighter
{
public:
    Highlight(QTextDocument* parent = nullptr);

protected:
    void highlightBlock(const QString& text);

private:
    // 定义字体属性
    QString fontFamily = "Consolas";
    int fontSize = 14;
    // 定义高亮规则
    struct HighlightRule{
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightRule> highlightRules;
    // 高亮指令和寄存器
    void highlightInst();
    void highlightRegs();
    void highlightComment();
};

#endif // HIGHLIGHT_H
