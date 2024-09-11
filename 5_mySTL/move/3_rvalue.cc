// 右值(Page 471)
#include <iostream>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // i是左值 42是右值
    int i = 42;

    // --- --- --- --- --- --- --- --- --- 左值
    // 算术运算符 返回右值的表达式
    // i * 42 是右值
    int &&ref3 = i * 42;

    // 关系运算符 返回右值的表达式
    // a && b 是右值
    int a = 2, b = 6;
    bool &&ref4 = a && b;

    // 解引用 返回右值的表达式
    // i2 >> 2 是右值
    int i2 = 1024;
    int &&ref5 = i2 >> 2;

    // 后置递增 后置递减 返回右值的表达式
    // i2++是左值 i2--是右值
    int &&ref6 = i2++;
    int &&ref7 = i2--;

    return 0;
}