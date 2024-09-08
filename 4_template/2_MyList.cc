// 基于 双向链表
#include <iostream>
#include <ostream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istringstream;
using std::ostream;
using std::string;

template <typename T>
class List
{
public:
    template <typename L>
    friend ostream &operator<<(ostream &os, const List<L> &pt);

private:
    // 定义节点
    struct Node
    {
        T data;
        Node *next;
        Node *prev;

        // 构造函数
        Node(const T &val, Node *nextNode = nullptr, Node *prevNode = nullptr)
            : data(val), next(nextNode), prev(prevNode) {}
    };

    Node *_head;
    Node *_tail;
    size_t _size;

public:
    // 构造函数
    List();

    // 析构函数
    ~List();

    // 在链表的末尾添加元素
    void push_back(const T &val);

    // 在链表的开头添加元素
    void push_front(const T &val);

    // 获取链表中节点的数量
    size_t getSize() const;

    // 访问链表中的元素
    T &operator[](size_t index);

    // 访问链表中的元素(const)
    const T &operator[](size_t index) const;

    // 删除链表末尾的元素
    void pop_back();

    // 删除链表开头的元素
    void pop_front();

    // 获取指定值的节点
    Node *getNode(const T &val);

    // 查找指定值的节点
    T *find(const T &val);

    // 删除指定值的节点
    void remove(const T &val);

    // 检查链表是否为空
    bool empty() const;

    // 清空链表
    void clear();

    // 使用迭代器遍历链表的开始位置
    Node *begin();

    // 使用迭代器遍历链表的结束位置
    Node *end();

    // 使用迭代器遍历链表的开始位置(const)
    const Node *begin() const;

    // 使用迭代器遍历链表的结束位置(const)
    const Node *end() const;

    // 打印链表中的元素
    void printElements() const;
};

// 构造函数
template <typename T>
List<T>::List() {}

// 析构函数
template <typename T>
List<T>::~List() {}

// 在链表的末尾添加元素
template <typename T>
void List<T>::push_back(const T &val) {}

// 在链表的开头添加元素
template <typename T>
void List<T>::push_front(const T &val) {}

// 获取链表中节点的数量
template <typename T>
size_t List<T>::getSize() const {}

// 访问链表中的元素(数据)
template <typename T>
T &List<T>::operator[](size_t index) {}

// 访问链表中的元素(数据)(const)
template <typename T>
const T &List<T>::operator[](size_t index) const {}

// 删除链表末尾的元素
template <typename T>
void List<T>::pop_back() {}

// 删除链表开头的元素
template <typename T>
void List<T>::pop_front() {}

// 获取指定值的节点
template <typename T>
typename List<T>::Node *List<T>::getNode(const T &val) {}

// 查找指定值的节点的引用
template <typename T>
T *List<T>::find(const T &val) {}

// 删除指定值的节点
template <typename T>
void List<T>::remove(const T &val) {}

// 检查链表是否为空
template <typename T>
bool List<T>::empty() const {}

// 清空链表
template <typename T>
void List<T>::clear() {}

// 使用迭代器遍历链表的开始位置
template <typename T>
typename List<T>::Node *List<T>::begin() {}

// 使用迭代器遍历链表的结束位置
template <typename T>
typename List<T>::Node *List<T>::end() {}

// 使用迭代器遍历链表的开始位置(const)
template <typename T>
const typename List<T>::Node *List<T>::begin() const {}

// 使用迭代器遍历链表的结束位置(const)
template <typename T>
const typename List<T>::Node *List<T>::end() const {}

// 打印链表中的元素
template <typename T>
void List<T>::printElements() const {}

// 重载运算符<<
template <typename T>
ostream &operator<<(ostream &os, const List<T> &pt) {}

int main()
{
    List<int> ilist;

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
        if (command == "push_back")
        {
            int val;
            iss >> val;
            ilist.push_back(val);
        }
        else if (command == "push_front")
        {
            int val;
            iss >> val;
            ilist.push_front(val);
        }
        else if (command == "pop_back")
        {
            ilist.pop_back();
        }
        else if (command == "pop_front")
        {
            ilist.pop_front();
        }
        else if (command == "remove")
        {
            int val;
            iss >> val;
            ilist.remove(val);
        }
        else if (command == "clear")
        {
            ilist.clear();
        }
        else if (command == "size")
        {
            // cout << ilist.size() << endl;
            cout << ilist.getSize() << endl;
        }
        else if (command == "get")
        {
            int index;
            iss >> index;
            cout << ilist[index] << endl;
        }
        else if (command == "print")
        {
            if (ilist.getSize() == 0)
            {
                cout << "empty" << endl;
            }
            else
            {
                ilist.printElements();
            }
        }
    }
    return 0;
}