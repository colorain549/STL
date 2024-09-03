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
    // 笔记: 可将 T *_elements 想象为数组  
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
Vector<T>::Vector() : _elements(nullptr), _capacity(0), _size(0) {}

// 析构函数
template <typename T>
Vector<T>::~Vector()
{
    delete[] _elements;
}

// 拷贝构造函数
template <typename T>
Vector<T>::Vector(const Vector &other) : _capacity(other._capacity), _size(other._size)
{
    // 分配内存
    _elements = new T[_capacity];
    // 从一个容器复制元素到另一个容器
    // 旧容器的迭代器开始位置 旧容器的迭代器结束位置 新容器的迭代器开始位置
    std::copy(other._elements, other._elements + _size, _elements);
}

// 拷贝赋值操作符
template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &other)
{
    // 防止自复制
    if (this != &other)
    {
        delete[] _elements;
        _capacity = other._capacity;
        _size = other._size();
        // 分配内存
        _elements = new T(_capacity);
        // 拷贝元素到新内存
        std::copy(other._elements, other._elements + _size, _elements);
    }
}

// 添加元素到数组末尾
template <typename T>
void Vector<T>::push_back(const T &val)
{
    if (_capacity == 0)
    {
        reserve(_capacity == 0 ? 1 : 2 * _capacity);
    }
    _elements[_size++] = val;
}

// 获取数组中元素的个数
template <typename T>
size_t Vector<T>::getSize() const
{
    return _size;
}

// 获取数组的容量
template <typename T>
size_t Vector<T>::getCapacity() const
{
    return _capacity;
}

// 访问数组中的元素
template <typename T>
T &Vector<T>::operator[](size_t index)
{
    // 检查
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("Index out of range.");
    }
    return _elements[index];
}

// 访问数组中的元素(const)
template <typename T>
const T &Vector<T>::operator[](size_t index) const
{
    // 检查
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("Index out of range.");
    }
    return _elements[index];
}

// 在指定位置插入元素
template <typename T>
void Vector<T>::insert(size_t index, const T &val)
{
    if (index < 0 || index > _size)
    {
        throw std::out_of_range("Index out of range.");
    }
    if (_size == _capacity)
    {
        reserve(_capacity == 0 ? 1 : 2 * _capacity);
    }
    for (size_t i = _size; i > index; --i)
    {
        _elements[i] = _elements[i - 1];
    }
    _elements[index] = val;
    ++_size;
}

// 删除数组末尾的元素
template <typename T>
void Vector<T>::pop_back()
{
    if (_size > 0)
    {
        --_size;
    }
}

// 清空数组
template <typename T>
void Vector<T>::clear()
{
    _size = 0;
}

// 迭代器开始的位置
template <typename T>
T *Vector<T>::begin()
{
    return _elements;
}

// 迭代器结束的位置
template <typename T>
T *Vector<T>::end()
{
    return _elements + _size;
}

// 迭代器开始的位置
template <typename T>
const T *Vector<T>::begin() const
{
    return _elements;
}

// 迭代器结束的位置
template <typename T>
const T *Vector<T>::end() const
{
    return _elements + _size;
}

// 打印数组中的元素
template <typename T>
void Vector<T>::printElements() const
{
    for (size_t i = 0; i < _size; ++i)
    {
        cout << _elements[i] << " ";
    }
    cout << endl;
}

// 扩展数组容量
template <typename T>
void Vector<T>::reserve(size_t newCapacity)
{
    // 若请求扩展的容量 大于 现有的容量
    if (newCapacity > _capacity)
    {
        // 分配内存
        T *newElements = new T(newCapacity);
        // 旧内存 复制到 新内存
        std::copy(_elements, _elements + _size, newElements);
        // 删除旧内存
        delete[] _elements;
        // 更新
        _elements = newElements;
        _capacity = newCapacity;
    }
}

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
            // if (ivec.empty())
            // {
            //     cout << "empty" << endl;
            // }
            // else
            // {
            //     // 下标遍历
            //     for (int i = 0; i < ivec.size(); i++)
            //     {
            //         cout << ivec[i] << " ";
            //     }
            //     cout << endl;
            // }
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