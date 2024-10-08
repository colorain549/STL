// 基于 完全二叉树实现的堆(这里是大顶堆)
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istringstream;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

template <typename T>
class PriorityQueue
{
private:
    shared_ptr<vector<T>> data;

    // 上浮
    void heapifyUp();

    // 下沉
    void heapifyDown();

public:
    // 构造函数
    PriorityQueue();

    // 将初始数组转化为堆
    PriorityQueue(const shared_ptr<vector<T>> &data);

    // 插入节点并调整
    void push(const T &val);

    // 删除节点并调节
    void pop();

    // 返回根结点
    T &top();

    // 队列是否为空
    bool empty() const;

    // 队列的长度
    size_t size() const;
};

// 上浮
template <typename T>
void PriorityQueue<T>::heapifyUp() {}

// 下沉
template <typename T>
void PriorityQueue<T>::heapifyDown() {}

// 构造函数
template <typename T>
PriorityQueue<T>::PriorityQueue() {}

// 将初始数组转化为堆
template <typename T>
PriorityQueue<T>::PriorityQueue(const shared_ptr<vector<T>> &data) {}

// 插入节点并调整
template <typename T>
void PriorityQueue<T>::push(const T &val) {}

// 删除节点并调节
template <typename T>
void PriorityQueue<T>::pop() {}

// 返回根结点
template <typename T>
T &PriorityQueue<T>::top() {}

// 队列是否为空
template <typename T>
bool PriorityQueue<T>::empty() const {}

// 队列的长度
template <typename T>
size_t PriorityQueue<T>::size() const {}

int main()
{
    PriorityQueue<int> pque;

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
            pque.push(val);
        }
        else if (command == "pop")
        {
            try
            {
                pque.pop();
            }
            catch (const std::runtime_error &e)
            {
                continue;
            }
        }
        else if (command == "top")
        {
            try
            {
                cout << pque.top() << endl;
            }
            catch (const std::runtime_error &e)
            {
                cout << "null" << endl;
            }
        }
        else if (command == "size")
        {
            cout << pque.size() << endl;
        }
        else if (command == "empty")
        {
            cout << (pque.empty() ? "true" : "false") << endl;
        }
    }

    // 用于测试带参的构造函数
    // auto ilist = std::initializer_list<int>{2, 6, 2, 1, 3};
    // auto ivec = make_shared<vector<int>>(ilist);
    // PriorityQueue<int> pque(ivec);
    // while (pque.size() > 0)
    // {
    //     cout << pque.top() << " ";
    //     pque.pop();
    // }
    // cout << endl;

    return 0;
}