#ifndef TOOL_H
#define TOOL_H

class Tool
{
public:
    double eval(const char s[]);
    int getPriority(char c);
    void pushSignOpera(char c);
    void pushSignNum(double n);
    void pushReverseOpera(char c);
    void pushReverseNum(double n);
    void deleteReverseItem(int pos);
    void insertReverseNum(int pos, double n);
    int isNumber(char c);
    int isOperator(char c);
    void pushOpera(char opera);
    int isNotEmptyOperaS();
    char popOpera();
    char getTopOpera();
    void replaceString(char s[], int pos, int len, char s1[]);
    void tranString(char s[]);
    int getOperaArgNum(char op);
    int long fact(int n);
    double calculate(double *n, char op, int num);
    void calculateOpera(char op, int pos);
};

#endif // TOOL_H
