// 基于 循环数组
#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;

template <typename T>
class Deque
{
private:
    T *_elements;
    size_t _capacity;
    size_t _frontIndex;
    size_t _backIndex;
    size_t _size;

public:
    // 构造函数
    Deque();

    // 析构函数
    ~Deque();

    // 在deque的前端插入元素
    void push_front(const T &val);

    // 在deque的后端插入元素
    void push_back(const T &val);

    // 从deque的前端移除元素
    void pop_front();

    // 从deque的后端移除元素
    void pop_back();

    // 随机访问元素
    T &operator[](int index);

    // 获取deque中的元素数量
    size_t getSize() const;

    // 清空deque
    void clear();

    // 打印deque中的元素
    void printElements() const;

private:
    // 扩展数组容量
    void resize();
};

// 构造函数
template <typename T>
Deque<T>::Deque() {}

// 析构函数
template <typename T>
Deque<T>::~Deque() {}

// 在deque的前端插入元素
template <typename T>
void Deque<T>::push_front(const T &val) {}

// 在deque的后端插入元素
template <typename T>
void Deque<T>::push_back(const T &val) {}

// 从deque的前端移除元素
template <typename T>
void Deque<T>::pop_front() {}

// 从deque的后端移除元素
template <typename T>
void Deque<T>::pop_back() {}

// 随机访问元素
template <typename T>
T &Deque<T>::operator[](int index) {}

// 获取deque中的元素数量
template <typename T>
size_t Deque<T>::getSize() const {}

// 清空deque
template <typename T>
void Deque<T>::clear() {}

// 打印deque中的元素
template <typename T>
void Deque<T>::printElements() const {}

// 扩展数组容量
template <typename T>
void Deque<T>::resize() {}

int main()
{
    Deque<int> dque;

    int N;
    cin >> N;
    //
    getchar();
    string line;
    for (int i = 0; i < N; ++i)
    {
        getline(cin, line);
        istringstream iss(line);
        string command;
        iss >> command;
        if (command == "push_back")
        {
            int val;
            iss >> val;
            dque.push_back(val);
        }
        else if (command == "push_front")
        {
            int val;
            iss >> val;
            dque.push_front(val);
        }
        else if (command == "clear")
        {
            dque.clear();
        }
        else if (command == "pop_back")
        {
            if (dque.getSize() == 0)
            {
                continue;
            }
            dque.pop_back();
        }
        else if (command == "pop_front")
        {
            if (dque.getSize() == 0)
            {
                continue;
            }
            dque.pop_front();
        }
        else if (command == "size")
        {
            cout << dque.getSize() << endl;
        }
        else if (command == "get")
        {
            int index;
            iss >> index;
            cout << dque[index] << endl;
        }
        else if (command == "print")
        {
            if (dque.getSize() == 0)
            {
                cout << "empty" << endl;
            }
            else
            {
                dque.printElements();
            }
        }
    }
    return 0;
}