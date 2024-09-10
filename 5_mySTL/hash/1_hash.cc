#include <iostream>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::hash;
using std::string;

size_t hashValue(const string &obj)
{
    // 创建哈希对象(用于哈希计算)
    // hash<string> hasher;
    // 使用哈希对象计算传入对象的哈希值
    // return hasher(obj);

    // hash<string>()创建临时哈希对象
    // ()是默认构造函数调用 生成一个实例
    // (obj)是对临时哈希对象的调用
    return hash<string>()(obj);
}

int main()
{
    string obj = "hiya";
    cout << hashValue(obj) << endl;

    return 0;
}