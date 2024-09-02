// 基于 维护 element capacity size
#include <iostream>
#include <memory>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::make_shared;
using std::shared_ptr;
using std::string;

template <typename T>
class Vector
{
private:
    T *_elements;
    size_t _capacity;
    size_t _size;

public:
    // 构造函数
    Vector();

    // 析构函数
    ~Vector();

    // 拷贝构造函数
    Vector(const Vector &other);

    // 拷贝赋值操作符
    Vector &operator=(const Vector &other);

    // 添加元素到数组末尾
    void push_back(const T &val);

    // 获取数组中元素的个数
    size_t getSize() const;

    // 获取数组的容量
    size_t getCapacity() const;

    // 访问数组中的元素
    T &operator[](size_t index);

    // 访问数组中的元素(const)
    const T &operator[](size_t index) const;

    // 在指定位置插入元素
    void insert(size_t index, const T &val);

    // 删除数组末尾的元素
    void pop_back();

    // 清空数组
    void clear();

    // 迭代器开始的位置
    T *begin();

    // 迭代器结束的位置
    T *end();

    // 迭代器开始的位置
    const T *begin() const;

    // 迭代器结束的位置
    const T *end() const;

    // 打印数组中的元素
    void printElements() const;

private:
    // 扩展数组容量
    void reserve(size_t newCapacity);
};

// 构造函数
template <typename T>
Vector<T>::Vector() {}

// 析构函数
template <typename T>
Vector<T>::~Vector() {}

// 拷贝构造函数
template <typename T>
Vector<T>::Vector(const Vector &other) {}

// 拷贝赋值操作符
template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &other) {}

// 添加元素到数组末尾
template <typename T>
void Vector<T>::push_back(const T &val) {}

// 获取数组中元素的个数
template <typename T>
size_t Vector<T>::getSize() const {}

// 获取数组的容量
template <typename T>
size_t Vector<T>::getCapacity() const {}

// 访问数组中的元素
template <typename T>
T &Vector<T>::operator[](size_t index) {}

// 访问数组中的元素(const)
template <typename T>
const T &Vector<T>::operator[](size_t index) const {}

// 在指定位置插入元素
template <typename T>
void Vector<T>::insert(size_t index, const T &val) {}

// 删除数组末尾的元素
template <typename T>
void Vector<T>::pop_back() {}

// 清空数组
template <typename T>
void Vector<T>::clear() {}

// 迭代器开始的位置
template <typename T>
T *Vector<T>::begin() {}

// 迭代器结束的位置
template <typename T>
T *Vector<T>::end() {}

// 迭代器开始的位置
template <typename T>
const T *Vector<T>::begin() const {}

// 迭代器结束的位置
template <typename T>
const T *Vector<T>::end() const {}

// 打印数组中的元素
template <typename T>
void Vector<T>::printElements() const {}

// 扩展数组容量
template <typename T>
void Vector<T>::reserve(size_t newCapacity) {}

int main()
{
    Vector<int> ivec;

    int N;
    cin >> N;
    // 读取回车
    getchar();

    string line;
    for (int i = 0; i < N; i++)
    {
        // 读取整行
        getline(cin, line);
        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "push")
        {
            int val;
            // 注意这里 从iss读取数据
            iss >> val;
            // 尾插
            ivec.push_back(val);
        }
        else if (command == "print")
        {
            if (ivec.getSize() == 0)
            {
                cout << "empty" << endl;
                continue;
            }
            ivec.printElements();
        }
        else if (command == "insert")
        {
            int index, val;
            iss >> index >> val;
            // 指定下标插入
            // ivec.insert(ivec.begin() + index, val);
            ivec.insert(index, val);
        }
        else if (command == "size")
        {
            // 获取长度(元素个数)
            // cout << ivec.size() << endl;
            cout << ivec.getSize() << endl;
        }
        else if (command == "get")
        {
            int index;
            iss >> index;
            // 下标访问
            cout << ivec[index] << endl;
        }
        else if (command == "pop")
        {
            // 删除最后一个元素
            // 思考: 如何使用erase
            ivec.pop_back();
        }
        else if (command == "iterator")
        {
            // 迭代器遍历
            // vector<int>::iterator it;
            if (ivec.getSize() == 0)
            {
                cout << "empty" << endl;
                continue;
            }
            for (auto it = ivec.begin(); it != ivec.end(); ++it)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
        else if (command == "foreach")
        {
            // 范围for循环
            for (const auto &elem : ivec)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
        else if (command == "clear")
        {
            // 删除容器内所有元素
            ivec.clear();
        }
    }
    return 0;
}