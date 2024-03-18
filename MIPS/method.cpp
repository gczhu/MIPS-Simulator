#include <windows.h>
#include "method.h"
#include "tool.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

void init_map(map<int,string> & map);
string construct_the_ins(int ins,map<int,string> reg);

int Method::execute(string str, const string& fileName, int pc)
{
    // 该操作能够执行汇编代码，也可以执行二进制代码
    // 在执行之前，我们先简单检查一下传入的是不是二进制代码
    int isBin = 1;

    vector<int> store;
    string output;
    map<int, string> regname;
    init_map(regname);
    int mem[100];
    int reg[32];

    ifstream reg_input("reg_state.txt"), mem_input("mem_state.txt");
    if(!reg_input.is_open() || !mem_input.is_open()){
        cout << "FILE OPEN ERROR";
    }
    for(int i = 0; i < 32; i++){
        reg_input >> reg[i];
    }
    for(int i = 0; i < 100; i++){
        mem_input >> mem[i];
    }
    reg_input.close();
    mem_input.close();

    for (int i = 0; i < str.length(); i++) {
        // 跳过注释
        if(str[i] == '#'){
            while(i < str.length() && str[i] != '\n'){
                i++;
            }
            i++;
        }
        // 跳过空格
        while(i < str.length() && str[i] == ' ' || str[i] == '\t' || str[i] == '\n'){
            i++;
        }
        // 判断是否为二进制
        if(i < str.length() && str[i] != '0' && str[i] != '1'){
            isBin = 0;
            break;
        }
    }

    // 如果传入的不是二进制代码，则需要先执行汇编操作
    if (!isBin) {
        // 得到其生成的二进制文件名
        int idx_postfix;
        for (int i = fileName.length() - 1; i >= 0; i--) {
            if(fileName[i] == '.'){
                idx_postfix = i;
                break;
            }
        }
        string asmFileName;
        if(idx_postfix > 0){
            asmFileName = fileName.substr(0, idx_postfix);
        }
        asmFileName += ".bin";
        ifstream execute(asmFileName);
        if(!execute.is_open()){
            cout << "FILE OPEN ERROR" << endl;
        }
        for(int i = 0; i <= pc; i++){
            getline(execute, str);
        }
    }
    // 如此，str中存放的就是汇编完成后的二进制代码，对该二进制代码进行解析执行即可
    for (int i = 0; i < str.length(); i++) {
        // 跳过注释
        if(str[i] == '#'){
            while(str[i] != '\n'){
                i++;
            }
            i++;
        }
        // 跳过空格
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'){
            i++;
        }
        // 判断是否为二进制
        if(str[i] != '0' && str[i] != '1'){
            isBin = 0;
            break;
        }
        //将这一位的二进制存储进vector中
        store.push_back(str[i] - '0');
    }

    int total_size = store.size();
    //如果总的二进制个数不是32的倍数，说明有不完全的指令，返回false
    if (total_size % 32 != 0)
    {
        return false;
    }

    int cur = 0;
    int ins = 0;
    int i = 0;

    //执行指令

    int opcode;
    int rs, rt, rd;
    int imm, sign;

    for (int i = 0;i<32;i++)
    {
        ins = (ins << 1) + store[cur++];
    }

    opcode = (ins & 0xFC000000 ) >> 26;

    if(opcode == 0){
        int func = (ins & 0b0000000000000000000000000111111);
        if (func == 0b100000)   //add
        {
            rs = (ins & 0b00000011111000000000000000000000) >> 21;
            rt = (ins & 0b00000000000111110000000000000000) >> 16;
            rd = (ins & 0b00000000000000001111100000000000) >> 11;
            reg[rd] = reg[rs] + reg[rt];


        } else if (func == 0b100111)    //nor
        {
            rs = (ins & 0b00000011111000000000000000000000) >> 21;
            rt = (ins & 0b00000000000111110000000000000000) >> 16;
            rd = (ins & 0b00000000000000001111100000000000) >> 11;
            reg[rd] = ~(reg[rs] | reg[rt]);


        } else if (func == 0b000000)    //sll
        {
            rt = (ins & 0b00000000000111110000000000000000) >> 16;
            rd = (ins & 0b00000000000000001111100000000000) >> 11;
            int sh =(ins & 0b00000000000000000000011111000000) >> 6;
            reg[rd] = reg[rt] << sh;


        } else if (func == 0b000010)    //srl
        {
            rt = (ins & 0b00000000000111110000000000000000) >> 16;
            rd = (ins & 0b00000000000000001111100000000000) >> 11;
            int sh =(ins & 0b00000000000000000000011111000000) >> 6;
            reg[rd] = reg[rt] >> sh;


        } else if (func == 0b101010)    //slt
        {
            rs = (ins & 0b00000011111000000000000000000000) >> 21;
            rt = (ins & 0b00000000000111110000000000000000) >> 16;
            rd = (ins & 0b00000000000000001111100000000000) >> 11;
            if(reg[rs] < reg[rt]){
                reg[rd] = 1;
            } else {
                reg[rd] = 0;
            }


        } else if (func == 0b001000)    //jr
        {
            rs = (ins & 0b00000011111000000000000000000000) >> 21;
            pc = reg[rs] - 1;


        } else                          //不包含该指令或指令错误
        {
            return -1;
        }

    } else if (opcode == 3)             //jal
    {
        int target = (ins & 0b00000011111111111111111111111111) ;   //存疑，要不要左移两位，地址似乎不用符号扩展

        reg[31] = pc + 1;
        pc = target - 1;


    } else if (opcode == 4)             //beq
    {
        rs = (ins & 0b00000011111000000000000000000000) >> 21;
        rt = (ins & 0b00000000000111110000000000000000) >> 16;
        imm = (ins & 0b00000000000000001111111111111111);
        sign =(ins & 0b00000000000000001000000000000000);
        if(sign > 0)
        {
            imm = imm | 0b11111111111111110000000000000000; // sign extension
        }
        if(reg[rs] == reg[rt]){
            pc = pc + imm;
        }


    } else if (opcode == 5)             //bne
    {
        rs = (ins & 0b00000011111000000000000000000000) >> 21;
        rt = (ins & 0b00000000000111110000000000000000) >> 16;
        imm = (ins & 0b00000000000000001111111111111111);
        sign =(ins & 0b00000000000000001000000000000000);
        if(sign > 0)
        {
            imm = imm | 0b11111111111111110000000000000000; // sign extension
        }
        if(reg[rs] != reg[rt]){
            pc = pc + imm;
        }


    } else if (opcode == 0b100011)  //lw
    {
        rs = (ins & 0b00000011111000000000000000000000) >> 21;
        rt = (ins & 0b00000000000111110000000000000000) >> 16;
        imm = (ins & 0b00000000000000001111111111111111);
        sign = (ins & 0b00000000000000001000000000000000);
        if(sign > 0)
        {
            imm = (signed int)(imm | 0b11111111111111110000000000000000); // sign extension
        }
        reg[rt] = mem[reg[rs] + imm];


    } else if (opcode == 0b101011)  //sw
    {
        rs = (ins & 0b00000011111000000000000000000000) >> 21;
        rt = (ins & 0b00000000000111110000000000000000) >> 16;
        imm = (ins & 0b00000000000000001111111111111111);
        sign = (ins & 0b00000000000000001000000000000000);
        if(sign > 0)
        {
            imm = (signed int)(imm | 0b11111111111111110000000000000000); // sign extension
        }
        mem[reg[rs] + imm] = reg[rt];


    } else if (opcode == 0b001000)  //addi
    {
        rs = (ins & 0b00000011111000000000000000000000) >> 21;
        rt = (ins & 0b00000000000111110000000000000000) >> 16;
        imm = (ins & 0b00000000000000001111111111111111);
        sign =(ins & 0b00000000000000001000000000000000);
        if(sign > 0)
        {
            imm = (signed int)(imm | 0b11111111111111110000000000000000); // sign extension
        }
        reg[rt] = reg[rs] + imm;


    } else {
        return -1;
    }
    ofstream reg_output("reg_state.txt"), mem_output("mem_state.txt");
    if(!reg_output.is_open() || !mem_output.is_open()){
        cout << "FILE OPEN ERROR";
    }
    for(int i = 0; i < 32; i++){
        reg_output << reg[i] << "\n";
    }
    for(int i = 0; i < 100; i++){
        mem_output << mem[i] << "\n";
    }
    reg_output.close();
    mem_output.close();

    // 打开文件进行写入
    std::ofstream outputFile(fileName);
    if(!outputFile.is_open()){
        cout << "FILE OPEN ERROR" << std::endl;
        return -1;
    }
    for(i = 0; i < 32; i ++){

        std::stringstream output;
        output << regname[i] << ": 0x" << std::hex << reg[i];
        std::string result = output.str();
        outputFile << result << std::endl;
    }
    outputFile << endl;

    for(i = 0; i < 100; i++){
        std::stringstream output;
        output << "mem[" << i << "]" << ": 0x" << std::hex << mem[i];
        std::string result = output.str();
        outputFile << result << std::endl;
    }

    outputFile.close();

    return pc + 1;
}

bool Method::assemble(string str, const string& fileName)
{
    // 由于我们汇编和反汇编的功能集成在一个页面
    // 所以这里先简单检查一下传入的是不是二进制代码
    int isBin = 1;
    for (int i = 0; i < str.length(); i++) {
        // 跳过注释
        if(str[i] == '#'){
            while(i < str.length() && str[i] != '\n'){
                i++;
            }
            i++;
        }
        // 跳过空格
        while(i < str.length() && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')){
            i++;
        }
        // 判断是否为二进制
        if(i < str.length() && str[i] != '0' && str[i] != '1'){
            isBin = 0;
            break;
        }
    }
    // 如果传入的是二进制代码，则直接返回false
    if (isBin) {
        return false;
    }
    // 否则，我们进行汇编
    ofstream input("input.txt");
    if(!input.is_open()){
        cout << "INPUT OPEN ERROR" << endl;
        return false;
    }
    input << str;
    input << endl << ".end";
    input.close();
    int len = 0, j;
    for(j = fileName.length() - 1; j >= 0; j--){
        if(fileName[j] == '/'){
            break;
        }
        len++;
    }
    string fileName1 = fileName.substr(j + 1, len);
    try {
        string exeName = "start /B mips_assembler.exe " + fileName1;
        system(exeName.c_str());
    } catch (exception e) {
        cout << "Execute ERROR" << endl;
        return false;
    }

    return true;
}

bool Method::disassemble(string str, const string& fileName)
{
    // 由于我们汇编和反汇编的功能集成在一个页面
    // 所以这里先简单检查一下传入的是不是二进制代码
    int isBin = 1;

    vector<int> store;
    string output;
    map<int, string> reg;

    for (int i = 0; i < str.length(); i++) {
        // 跳过注释
        if(str[i] == '#'){
            while(i < str.length() && str[i] != '\n'){
                i++;
            }
            i++;
        }
        // 跳过空格
        while(i < str.length() && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')){
            i++;
        }
        // 判断是否为二进制
        if(i < str.length() && str[i] != '0' && str[i] != '1'){
            isBin = 0;
            break;
        }
        //将这一位的二进制存储进vector中
        if(i < str.length()){
            store.push_back(str[i] - '0');
        }
    }
    // 如果传入的不是二进制代码，则直接返回false
    if (!isBin) {
        return false;
    }
    // 否则，我们进行反汇编
    int total_size = store.size();
    //如果总的二进制个数不是32的倍数，说明有不完全的指令
    if (total_size % 32 != 0)
    {
        return false;
    }

    int cur = 0;
    int ins = 0;
    init_map(reg);
    while (cur < total_size)
    {
        ins = 0;
        for (int i = 0;i<32;i++)
        {
            ins = (ins << 1) + store[cur++];
        }
        string result = construct_the_ins(ins,reg);
        // write the string to the file
        if (result == "fail")
        {
            return false;   // the instruction is wrong
        } else {
            output += result;
            output += "\n";
        }
    }

    //将output写进文件中去
    fstream f;
    f.open(fileName,ios::out);
    f << output << endl;
    f.close();
    return true;
}

string Method::convert(string str, int choice)
{
    string res = "", tmp = "", tmp1 = "", tmp2 = "", op1, op2;
    char operation;
    char res1[33];
    int num, flag = 0, count = 0, ans = 0, exp = 0, pos, isZero = 0, mark = 0, pint, idx;
    double frac = 0, ansf = 0, numf, pfrac, mul;
    switch(choice){
    case 1:     // 整数->补码
        num = atoi(str.c_str());
        if(num == 0 && str != "0"){
            return "ERROR";
        }
        if(num < 0){
            num = -num;
            flag = 1;
        }
        while(count < 32){
            int bit = num % 2;
            num /= 2;
            res += (bit == 1) ? "1" : "0";
            count++;
        }
        reverse(res.begin(), res.end());
        if(flag == 1){      // 如果是负数
            // 取反
            for (int i = 0; i < 32; i++) {
                res[i] = (res[i] == '0') ? '1' : '0';
            }
            // 加一
            for (int i = 31; i >= 0; i--) {
                if(res[i] == '1'){
                    res[i] = '0';
                }else{
                    res[i] = '1';
                    break;
                }
            }
        }
        break;
    case 2:     // 补码->整数
        for (int i = 0; i < str.length(); i++) {
            if(str[i] != '0' && str[i] != '1'){
                return "ERROR";
            }
        }
        if(str.length() > 32){
            return "ERROR";
        }else if(str.length() < 32){
            count = str.length();
            while(count < 32){
                tmp += str[0];
                count++;
            }
            tmp += str;
        }else{
            tmp = str;
        }
        if(tmp[0] == '1'){
            flag = 1;
            // 取反
            for (int i = 0; i < 32; i++) {
                tmp[i] = (tmp[i] == '0') ? '1' : '0';
            }
            // 加一
            for (int i = 31; i >= 0; i--) {
                if(tmp[i] == '1'){
                    tmp[i] = '0';
                }else{
                    tmp[i] = '1';
                    break;
                }
            }
        }
        for (int i = 1; i < 32; i++) {
            ans = ans * 2 + tmp[i] - '0';
        }
        if(flag == 1){
            ans = -ans;
        }
        itoa(ans, res1, 10);
        res = string(res1);
        break;
    case 3:     // 浮点数->二进制
        numf = atof(str.c_str());
        if(numf == 0){
            for (int i = 0; i < str.length(); i++) {
                if(str[i] != '0'){
                    if(str[i] == '.'){
                        // 只允许出现一个小数点
                        if(mark == 1){
                            return "ERROR";
                        }else{
                            mark = 1;
                        }
                    }else{
                        return "ERROR";
                    }
                }
            }
            return "00000000000000000000000000000000";
        }
        if(numf < 0){
            numf = -numf;
            flag = 1;
        }
        // 将浮点数拆分为整数和小数两个部分
        pint = (int)numf;
        pfrac = numf - pint;
        if(pint == 0){
            tmp += '0';
        }
        while(pint > 0){
            int bit = pint % 2;
            pint /= 2;
            tmp += (bit == 1) ? "1" : "0";
        }
        reverse(tmp.begin(), tmp.end());
        tmp += '.';
        while(count < 32 && pfrac != 0){
            pfrac *= 2;
            if(pfrac >= 1){
                pfrac -= 1;
                tmp += '1';
            }else{
                tmp += '0';
            }
            count++;
        }
        idx = tmp.find('.');
        while(idx > 1){
            char ch = tmp[idx];
            tmp[idx] = tmp[idx-1];
            tmp[idx-1] = ch;
            idx--;
            exp++;
        }
        while(tmp[idx-1] == '0'){
            char ch = tmp[idx];
            tmp[idx] = tmp[idx+1];
            tmp[idx+1] = ch;
            idx++;
            exp--;
        }
        tmp1 = tmp.substr(idx + 1, tmp.length() - idx - 1);
        if(tmp1.length() > 23){
            tmp1 = tmp1.substr(0, 23);
        }
        while(tmp1.length() < 23){
            tmp1 += '0';
        }
        exp += 127;
        frac = atoi(tmp1.c_str());
        // 判断特殊情况
        if(exp == 0 && frac != 0){
            return "DENORMALS";
        }else if(exp == 255 && frac == 0){
            return "INFINITY";
        }else if(exp == 255 && frac != 0){
            return "NAN";
        }
        // 拼接字符串得到结果
        count = 0;
        res += to_string(flag);
        while(count < 8){
            int bit = exp % 2;
            exp /= 2;
            tmp2 += (bit == 1) ? "1" : "0";
            count++;
        }
        reverse(tmp2.begin(), tmp2.end());
        res += tmp2 + tmp1;
        break;
    case 4:     // 二进制->浮点数
        for (int i = 0; i < str.length(); i++) {
            if(str[i] != '0' && str[i] != '1'){
                return "ERROR";
            }
        }
        if(str.length() != 32){
            return "ERROR";
        }
        if(str[0] == '1'){
            flag = 1;
        }
        // 得到指数和尾数
        tmp = "0.";
        tmp += str.substr(9, 23);
        frac = atof(tmp.c_str());
        for (int i = 1; i <= 8; i++) {
            exp = exp * 2 + str[i] - '0';
        }
        // 判断特殊情况
        if(exp == 0 && frac == 0){
            return "0";
        }else if(exp == 0 && frac != 0){
            return "DENORMALS";
        }else if(exp == 255 && frac == 0){
            return "INFINITY";
        }else if(exp == 255 && frac != 0){
            return "NAN";
        }
        // 计算结果
        frac += 1;
        exp -= 127;
        tmp1 = to_string(frac);
        idx = tmp1.find('.');
        for (int i = 0; i < idx; i++) {
            ansf = ansf * 2 + tmp1[i] - '0';
        }
        mul = 0.5;
        for (int i = idx + 1; i < tmp1.length(); i++) {
            ansf += (tmp1[i] - '0') * mul;
            mul /= 2;
        }
        ansf *= pow(2, exp);
        if(flag == 1){
            ansf = -ansf;
        }
        res = to_string(ansf);
        // 除去后置0
        pos = res.length() - 1;
        while(pos > 0 && (res[pos] == '0' || res[pos] == '.')){
            pos--;
        }
        res = res.substr(0, pos + 1);
        break;
    case 5:     // 浮点数运算
        Tool* tool = new Tool();
        numf = tool->eval(str.c_str());
        res = to_string(numf);
        // 除去后置0
        pos = res.length() - 1;
        while(pos > 0 && (res[pos] == '0' || res[pos] == '.')){
            pos--;
        }
        res = res.substr(0, pos + 1);
        break;
    }
    return res;
}

string construct_the_ins(int ins,map<int,string> reg)   //如果指令错误则返回fail
{
    string back;
    /**
     * mips的二进制指令有两种切分方式： 6 5 5 5 5 6 or 6 5 5 16
     * 可以先读最高位的6位，然后使用swith语句进行后续的划分
    */
    int opcode = (ins & 0xFC000000 ) >> 26;
    int s,t,d;
    int imm, sign;
    string simm;
    string rs,rt,rd;
    if (opcode == 0)
    {
        int func = (ins & 0b0000000000000000000000000111111);
        if (func == 0b100000)   //add
        {
            s = (ins & 0b00000011111000000000000000000000) >> 21;
            t = (ins & 0b00000000000111110000000000000000) >> 16;
            d = (ins & 0b00000000000000001111100000000000) >> 11;
            rs = reg[s];
            rt = reg[t];
            rd = reg[d];
            back = "add " + rd + "," + rs + "," + rt;
        } else if (func == 0b100111)    //nor
        {
            s = (ins & 0b00000011111000000000000000000000) >> 21;
            t = (ins & 0b00000000000111110000000000000000) >> 16;
            d = (ins & 0b00000000000000001111100000000000) >> 11;
            rs = reg[s];
            rt = reg[t];
            rd = reg[d];
            back = "nor " + rd + "," + rs + "," + rt;
        } else if (func == 0b000000)    //sll
        {
            t = (ins & 0b00000000000111110000000000000000) >> 16;
            d = (ins & 0b00000000000000001111100000000000) >> 11;
            rd = reg[d];
            rt = reg[t];
            int sh =(ins & 0b00000000000000000000011111000000) >> 6;
            string shamt = to_string(sh);
            back = "sll " + rd + "," + rt + "," + shamt;
        } else if (func == 0b000010)    //srl
        {
            t = (ins & 0b00000000000111110000000000000000) >> 16;
            d = (ins & 0b00000000000000001111100000000000) >> 11;
            rd = reg[d];
            rt = reg[t];
            int sh =(ins & 0b00000000000000000000011111000000) >> 6;
            string shamt = to_string(sh);
            back = "srl " + rd + "," + rt + "," + shamt;
        } else if (func == 0b101010)    //slt
        {
            s = (ins & 0b00000011111000000000000000000000) >> 21;
            t = (ins & 0b00000000000111110000000000000000) >> 16;
            d = (ins & 0b00000000000000001111100000000000) >> 11;
            rs = reg[s];
            rt = reg[t];
            rd = reg[d];
            back = "slt " + rd + "," + rs + "," + rt;
        } else if (func == 0b001000)    //jr
        {
            s = (ins & 0b00000011111000000000000000000000) >> 21;
            rs = reg[s];
            back = "jr " + rs;
        } else {
            return "fail";
        }
    } else if (opcode == 3) //jal
    {
        int target = (ins & 0b00000011111111111111111111111111) ;   //存疑，要不要左移两位，地址似乎不用符号扩展
        string target_address = to_string(target);
        back = "jal " + target_address;
    } else if (opcode == 4){    //beq
        s = (ins & 0b00000011111000000000000000000000) >> 21;
        t = (ins & 0b00000000000111110000000000000000) >> 16;
        rs = reg[s];
        rt = reg[t];
        imm = (ins & 0b00000000000000001111111111111111);
        sign =(ins & 0b00000000000000001000000000000000);
        if(sign > 0)
        {
            imm = imm | 0b11111111111111110000000000000000; // sign extension
        }
        simm = to_string(imm);
        back = "beq " + rs + "," + rt + "," + simm;
    } else if (opcode == 5) //bne
    {
        s = (ins & 0b00000011111000000000000000000000) >> 21;
        t = (ins & 0b00000000000111110000000000000000) >> 16;
        rs = reg[s];
        rt = reg[t];
        imm = (ins & 0b00000000000000001111111111111111);
        sign =(ins & 0b00000000000000001000000000000000);
        if(sign > 0)
        {
            imm = imm | 0b11111111111111110000000000000000; // sign extension
        }
        simm = to_string(imm);
        back = "bne " + rs + "," + rt + "," + simm;
    } else if (opcode == 0b100011)  //lw
    {
        s = (ins & 0b00000011111000000000000000000000) >> 21;
        t = (ins & 0b00000000000111110000000000000000) >> 16;
        rs = reg[s];    //基址寄存器
        rt = reg[t];    //目的寄存器
        imm = (ins & 0b00000000000000001111111111111111);
        sign =(ins & 0b00000000000000001000000000000000);
        if(sign > 0)
        {
            imm = (signed int)(imm | 0b11111111111111110000000000000000); // sign extension
        }
        simm = to_string(imm);
        back = "lw " + rt + "," + simm + "(" + rs + ")";
    } else if (opcode == 0b101011)  //sw
    {
        s = (ins & 0b00000011111000000000000000000000) >> 21;
        t = (ins & 0b00000000000111110000000000000000) >> 16;
        rs = reg[s];    //基址寄存器
        rt = reg[t];    //目的寄存器
        imm = (ins & 0b00000000000000001111111111111111);
        sign =(ins & 0b00000000000000001000000000000000);
        if(sign > 0)
        {
            imm = (signed int)(imm | 0b11111111111111110000000000000000); // sign extension
        }
        simm = to_string(imm);
        back = "sw " + rt + "," + simm + "(" + rs + ")";
    } else if (opcode == 0b001000)  //addi
    {
        s = (ins & 0b00000011111000000000000000000000) >> 21;
        t = (ins & 0b00000000000111110000000000000000) >> 16;
        rs = reg[s];
        rt = reg[t];
        imm = (ins & 0b00000000000000001111111111111111);
        sign =(ins & 0b00000000000000001000000000000000);
        if(sign > 0)
        {
            imm = (signed int)(imm | 0b11111111111111110000000000000000); // sign extension
        }
        simm = to_string(imm);
        back = "addi " + rt + "," + rs + "," + simm;
    } else {
        return "fail";
    }
    return back;
}

void init_map(map<int,string> & map)
{
    map[0] = "$zero";
    map[1] = "$at";
    map[2] = "$v0";
    map[3] = "$v1";
    map[4] = "$a0";
    map[5] = "$a1";
    map[6] = "$a2";
    map[7] = "$a3";
    map[8] = "$t0";
    map[9] = "$t1";
    map[10] = "$t2";
    map[11] = "$t3";
    map[12] = "$t4";
    map[13] = "$t5";
    map[14] = "$t6";
    map[15] = "$t7";
    map[16] = "$s0";
    map[17] = "$s1";
    map[18] = "$s2";
    map[19] = "$s3";
    map[20] = "$s4";
    map[21] = "$s5";
    map[22] = "$s6";
    map[23] = "$s7";
    map[24] = "$t8";
    map[25] = "$t9";
    map[26] = "$k0";
    map[27] = "$k1";
    map[28] = "$gp";
    map[29] = "$sp";
    map[30] = "$fp";
    map[31] = "$ra";
}
