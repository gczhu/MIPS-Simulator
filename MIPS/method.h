#ifndef METHOD_H
#define METHOD_H

#include <string>
using namespace std;

class Method
{
public:
    /** execute
     * 功能：执行代码到光标所在行
     * 输入：从开始到光标所在行的代码str，写入结果的文件路径fileName
     * 输出：将寄存器和内存的状态按指定格式写入文件fileName(有则覆盖，无则新建)
     * 输出格式：$t0+"\t"+value 或 Memory[0]+"\t"+value
     *         一行记录一个寄存器或者内存单元的值
     * tips：可用大小为65535的整型数组存储内存单元的值，初始化为0
     */
    int execute(string str, const string& fileName, int pc);
    /** assemble
     * 功能：汇编
     * 输入：汇编代码str，写入结果的文件路径fileName
     * 输出：将汇编得到的二进制代码按行写入文件fileName(有则覆盖，无则新建)
     */
    bool assemble(string str, const string& fileName);
    /** disassemble
     * 功能：反汇编
     * 输入：二进制代码str，写入结果的文件路径fileName
     * 输出：将反汇编得到的汇编代码按行写入文件fileName(有则覆盖，无则新建)
     */
    bool disassemble(string str, const string& fileName);
    /** convert
     * 功能：整数->二进制补码表示 浮点数->二进制表示 浮点数运算
     * 输入：表示整数/浮点数的字符串str，功能选项choice
     * 输出：转换/计算结果
     */
    string convert(string str, int choice);
};

#endif // METHOD_H
