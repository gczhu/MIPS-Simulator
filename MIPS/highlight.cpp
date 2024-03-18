#include "highlight.h"

Highlight::Highlight(QTextDocument* parent) : QSyntaxHighlighter(parent)
{
    // 高亮指令
    highlightInst();
    // 高亮寄存器
    highlightRegs();
    // 高亮注释
    highlightComment();
}

void Highlight::highlightBlock(const QString &text)
{
    foreach (const HighlightRule& rule, highlightRules) {
        QRegularExpression regExp(rule.pattern);
        QRegularExpressionMatchIterator it = regExp.globalMatch(text);
        while(it.hasNext()){
            QRegularExpressionMatch match = it.next();
            int start = match.capturedStart(0);
            int end = match.capturedEnd(0);
            setFormat(start, end - start, rule.format);
        }
    }
}

void Highlight::highlightInst()
{
    HighlightRule rule;
    rule.pattern.setPattern("add|lw|sw|nor|sll|srl|beq|bne|slt|jr|jal");     // 匹配各个指令
    rule.pattern.setPatternOptions(QRegularExpression::CaseInsensitiveOption);      // 大小写不敏感
    QFont font = QFont(fontFamily, fontSize);
    font.setBold(true);
    rule.format.setFont(font);
    rule.format.setForeground(Qt::darkBlue);
    highlightRules.append(rule);
    rule.pattern.setPattern("addi");     // 由于addi包含add，故单独处理
    highlightRules.append(rule);
}

void Highlight::highlightRegs()
{
    HighlightRule rule;
    rule.pattern.setPattern("\\$s[0-7]|\\$t[0-9]|\\$zero|\\$a[0-3]|\\$v[0-1]|\\$gp|\\$fp|\\$sp|\\$ra|\\$at");     // 匹配各个寄存器
    QFont font = QFont(fontFamily, fontSize);
    font.setBold(true);
    rule.format.setFont(font);
    rule.format.setForeground(Qt::darkRed);
    highlightRules.append(rule);
}

void Highlight::highlightComment()
{
    HighlightRule rule;
    rule.pattern.setPattern("#.*$");     // 匹配注释
    QFont font = QFont(fontFamily, fontSize);
    rule.format.setFont(font);
    rule.format.setForeground(Qt::darkGreen);
    highlightRules.append(rule);
}
