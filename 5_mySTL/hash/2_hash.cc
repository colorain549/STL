#include <iostream>
#include <functional>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::hash;
using std::string;

template <typename Hash = hash<string>>
size_t hashValue(const string &obj)
{
    // Hash hasher;
    // return hasher(obj);

    return Hash()(obj);
}

int main()
{
    string key = "hello";
    cout << hashValue(key) << endl;

    return 0;
}