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
class Queue
{
private:
    shared_ptr<deque<T>> _dque;

public:
    // 构造函数
    Queue();

    // 将元素添加到队尾
    void push(const T &val);

    // 移除队头元素
    void pop();

    // 访问队头元素的引用
    T &front();

    // 访问队末元素的引用
    T &back();

    // 检查队列是否为空
    bool empty() const;

    // 返回队列的大小
    size_t size() const;
};

// 构造函数
template <typename T>
Queue<T>::Queue() {}

// 将元素添加到队尾
template <typename T>
void Queue<T>::push(const T &val) {}

// 移除队头元素
template <typename T>
void Queue<T>::pop() {}

// 访问队头元素的引用
template <typename T>
T &Queue<T>::front() {}

// 访问队末元素的引用
template <typename T>
T &Queue<T>::back() {}

// 检查队列是否为空
template <typename T>
bool Queue<T>::empty() const {}

// 返回队列的大小
template <typename T>
size_t Queue<T>::size() const {}

int main()
{
    Queue<int> que;

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
            que.push(val);
        }
        else if (command == "size")
        {
            cout << que.size() << endl;
        }
        else if (command == "front")
        {
            if (que.empty())
            {
                cout << "null" << endl;
            }
            else
            {
                cout << que.front() << endl;
            }
        }
        else if (command == "back")
        {
            if (que.empty())
            {
                cout << "null" << endl;
            }
            else
            {
                cout << que.back() << endl;
            }
        }
        else if (command == "pop")
        {
            if (que.empty())
            {
                continue;
            }
            else
            {
                que.pop();
            }
        }
        else if (command == "empty")
        {
            cout << (que.empty() ? "true" : "false") << endl;
        }
    }
    return 0;
}
