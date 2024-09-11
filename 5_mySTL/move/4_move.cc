// std::move (Page 472)
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

    // 将左值转换为右值引用类型
    int &&ans = std::move(i);
    
    return 0;
}