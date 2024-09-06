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
    // 重载<<运算符 用来输出 List<T> 对象的内容
    template <typename L>
    friend ostream &operator<<(ostream &os, const List<L> &pt);

private:
    // 定义节点
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
        // 构造函数 初始化 数据成员
        Node(const T &val, Node *nextNode = nullptr, Node *prevNode = nullptr)
            : data(val), next(nextNode), prev(prevNode) {}
    };

    // 数据成员
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

    // 查找指定值的节点的值
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
List<T>::List() : _head(nullptr), _tail(nullptr), _size(0) {}

// 析构函数
template <typename T>
List<T>::~List()
{
    clear();
}

// 在链表的末尾添加元素
template <typename T>
void List<T>::push_back(const T &val)
{
    // Node(val, next, pre)
    // 笔记:
    // newNode->next = nullptr;
    // newNode->pre = _tail;
    Node *newNode = new Node(val, nullptr, _tail);
    if (_tail)
    {
        _tail->next = newNode;
    }
    else
    {
        _head = newNode;
    }
    // 在末尾添加, _tail动了, 所以需改动_tail
    _tail = newNode;
    _size++;
}

// 在链表的开头添加元素
template <typename T>
void List<T>::push_front(const T &val)
{
    // Node(val, next, pre)
    // 笔记:
    // newNode->next = _head;
    // _head->pre = nullptr;
    Node *newNode = new Node(val, _head, nullptr);
    if (_head)
    {
        _head->prev = newNode;
    }
    else
    {
        _tail = newNode;
    }
    // 在开头添加, _head动了, 所以需改动_head
    _head = newNode;
    ++_size;
}

// 获取链表中节点的数量
template <typename T>
size_t List<T>::getSize() const
{
    return _size;
}

// 访问链表中的元素
template <typename T>
T &List<T>::operator[](size_t index)
{
    Node *cur = _head;
    for (size_t i = 0; i < index; i++)
    {
        // 注意: 将错误处理放到这里
        if (index < 0 || index > _size - 1)
        {
            std::out_of_range("Index out of range.");
        }
        cur = cur->next;
    }
    return cur->data;
}

// 访问链表中的元素(const)
template <typename T>
const T &List<T>::operator[](size_t index) const
{

    Node *cur = _head;
    for (size_t i = 0; i < index; i++)
    {
        // 注意: 将错误处理放到这里
        if (index < 0 || index > _size - 1)
        {
            std::out_of_range("Index out of range.");
        }
        cur = cur->next;
    }
    return cur->data;
}

// 删除链表末尾的元素
template <typename T>
void List<T>::pop_back()
{
    // 检查
    if (_size > 0)
    {
        // 保存上一节点
        Node *newTail = _tail->prev;
        // 释放内存
        delete _tail;
        // 重置指向
        _tail = newTail;
        // 检查是否为空
        if (_tail)
        {
            _tail->next = nullptr;
        }
        else
        {
            _tail = nullptr;
        }
        --_size;
    }
}

// 删除链表开头的元素
template <typename T>
void List<T>::pop_front()
{
    // 检查
    if (_size > 0)
    {
        // 保存下一节点
        Node *newHead = _head->next;
        // 释放内存
        delete _head;
        // 重置指向
        _head = newHead;
        // 检查是否为空
        if (_head)
        {
            _head->prev = nullptr;
        }
        else
        {
            _tail = nullptr;
        }
        --_size;
    }
}

// 获取指定值的节点
template <typename T>
typename List<T>::Node *List<T>::getNode(const T &val)
{
    Node *cur = _head;
    while (cur != nullptr && cur->val != val)
    {
        cur = cur->next;
    }
    return cur;
}

// 查找指定值的节点的值
template <typename T>
T *List<T>::find(const T &val)
{
    // 调用成员函数
    Node *cur = getNode(val);
    // 找不到则返回nullptr
    if (cur == nullptr)
    {
        return nullptr;
    }
    // 找到直接返回
    return &cur->val;
}

// 删除指定值的节点
template <typename T>
void List<T>::remove(const T &val)
{
    Node *cur = _head;
    while (cur != nullptr && cur->data != val)
    {
        cur = cur->next;
    }
    // 找不到指定值
    if (cur == nullptr)
    {
        return;
    }
    // 既不是头结点 也不是尾节点
    if (cur != _head && cur != _tail)
    {
        // !!!建议: 画图理解!!!双链表精粹!!!
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    // 既是头结点 也是尾节点 只有1个节点 删除后为空
    else if (cur == _head && cur == _tail)
    {
        _head = nullptr;
        _tail = nullptr;
    }
    // 是头结点 更新头节点为下一节点 及更新 新头节点的前驱_head->prev
    else if (cur == _head)
    {
        _head = cur->next;
        _head->prev = nullptr;
    }
    // 是尾节点 更新尾节点为上一节点 及更新 新尾节点的后驱_tail->next
    else
    {
        _tail = cur->prev;
        _tail->next = nullptr;
    }

    --_size;
    delete cur;
    cur = nullptr;
}

// 检查链表是否为空
template <typename T>
bool List<T>::empty() const
{
    return _size == 0;
}

// 清空链表
template <typename T>
void List<T>::clear()
{
    // 遍历节点 保存当前节点为临时节点
    // 到下一个节点时 删除临时节点
    Node *cur = _head;
    while (cur)
    {
        Node *tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    // 记得更新_tail
    _tail = nullptr;
    _size = 0;
}

// 使用迭代器遍历链表的开始位置
template <typename T>
typename List<T>::Node *List<T>::begin()
{
    return _head;
}

// 使用迭代器遍历链表的结束位置
template <typename T>
typename List<T>::Node *List<T>::end()
{
    return nullptr;
}

// 使用迭代器遍历链表的开始位置(const)
template <typename T>
const typename List<T>::Node *List<T>::begin() const
{
    return _head;
}

// 使用迭代器遍历链表的结束位置(const)
template <typename T>
const typename List<T>::Node *List<T>::end() const
{
    return nullptr;
}

// 打印链表中的元素
template <typename T>
void List<T>::printElements() const
{
    Node *cur = _head;
    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 重载运算符<<
template <typename T>
ostream &operator<<(ostream &os, const List<T> &pt)
{
    // 笔记: 记住auto cur = pt._head
    for (auto cur = pt._head; cur != nullptr; cur = cur->next)
    {
        os << " " << cur->data;
    }
    os << endl;
    return os;
}

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