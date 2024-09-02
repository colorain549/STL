// 基于 完全二叉树实现的堆(这里是大顶堆)
#include <iostream>
#include <vector>;

using std::cin;
using std::cout;
using std::endl;
using std::vector;

template <typename T, typename Container = vector<T>>
class MyPriorityQueue
{
private:
    Container data;

    // 上浮
    void heapifyUp();

    // 下沉
    void heapifyDown();

public:
    // 构造函数
    MyPriorityQueue();

    // 将底层容器转化为堆(用数组的形式表示堆?)
    MyPriorityQueue(const Container &c);

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

template <typename T, typename Container>
void MyPriorityQueue<T, Container>::heapifyUp() {}

template <typename T, typename Container>
void MyPriorityQueue<T, Container>::heapifyDown() {}

// 构造函数
template <typename T, typename Container>
MyPriorityQueue<T, Container>::MyPriorityQueue() {}

int main()
{
    return 0;
}