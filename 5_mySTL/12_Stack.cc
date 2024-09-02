// 基于 双端队列 deque
#include <iostream>
#include <deque>
#include <vector>
#include <memory>
#include <sstream>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::getline;
using std::istringstream;
using std::make_shared;
using std::shared_ptr;
using std::string;

template <typename T>
class Stack
{
private:
    shared_ptr<deque<int>> _dque;

public:
    // 构造函数
    Stack();

    // 压入元素
    void push(const T &val);

    // 弹出元素
    void pop();

    // 返回栈顶元素的引用
    T &top();

    // 栈是否为空
    bool empty();

    // 栈的大小
    size_t size() const;
};

// 构造函数
template <typename T>
Stack<T>::Stack() : _dque(make_shared<deque<T>>()) {}

// 压入元素
template <typename T>
void Stack<T>::push(const T &val)
{
    _dque->push_back(val);
}

// 弹出元素
template <typename T>
void Stack<T>::pop()
{
    if (!empty())
    {
        _dque->pop_back();
    }
    else
    {
        throw std::runtime_error("Stack is empty.");
    }
}

// 返回栈顶元素的引用
template <typename T>
T &Stack<T>::top()
{
    if (!empty())
    {
        return _dque->back();
    }
    else
    {
        throw std::runtime_error("Stack is empty.");
    }
}

// 栈是否为空
template <typename T>
bool Stack<T>::empty()
{
    return _dque->empty();
}

// 栈的大小
template <typename T>
size_t Stack<T>::size() const
{
    return _dque->size();
}

int main()
{
    // MyStack<int, deque<int>> st;
    Stack<int> st;

    int N;
    cin >> N;
    getchar();

    string line;
    for (int i = 0; i < N; i++)
    {
        getline(cin, line);
        istringstream iss(line);
        string command;
        iss >> command;
        if (command == "push")
        {
            int val;
            iss >> val;
            st.push(val);
        }
        else if (command == "size")
        {
            cout << st.size() << endl;
        }
        else if (command == "empty")
        {
            cout << (st.empty() ? "true" : "false") << endl;
        }
        else if (command == "pop")
        {
            st.pop();
        }
        else if (command == "top")
        {
            if (st.empty())
            {
                cout << "null" << endl;
            }
            else
            {
                cout << st.top() << endl;
            }
        }
    }

    return 0;
}