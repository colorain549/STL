// 左值(Page 471)
#include <iostream>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // --- --- --- --- --- --- --- --- --- 左值
    // 赋值运算符 返回左值的表达式
    // s是左值 "hi"是右值
    string s = "hi";
    string &ref3 = s;

    // 下标 返回左值的表达式
    // ch是左值 s[0]也是左值
    char ch = s[0];
    char &ref4 = ch;

    // 解引用 返回左值的表达式
    // *p是左值
    int i2 = 2;
    int &ref5 = *(&i2);

    // 前置递增 前置递减 返回左值的表达式
    // ++i2是左值 --i2是右值
    int &ref6 = ++i2;
    int &ref7 = --i2;

    return 0;
}