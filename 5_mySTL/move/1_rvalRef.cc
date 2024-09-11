// 右值引用(Page 471)
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

    // --- --- --- --- --- --- --- --- --- 左值引用
    // 引用(即对象的别名)
    // 左值引用 绑定到 左值
    int &ref = i;

    // --- --- --- --- --- --- --- --- --- 右值引用
    // (!!!)右值引用 绑定到 右值(!!!)
    int &&rval = 421;
    // (!!!)右值引用 绑定到 右值(!!!)
    int &&rval3 = i * 42;

    // --- --- --- --- --- --- --- --- ---  const左值引用
    // (!!!)将const的左值引用 绑定到 右值(!!!)
    const int &ref3 = i * 42;

    // --- --- --- --- --- --- --- --- ---  错误的绑定
    // 不能将 右值引用 绑定到 左值
    // int &&rval = i;

    // (!!!)i*42是右值(算数运算符生成右值)(!!!)
    // 不能将 左值引用 绑定到 右值
    // int &ref2 = i * 42;   

    return 0;
}
