// 1. 类模版 + HashTable类
// 2. HashNode类 + 私有前向声明
// 3. 私有数据成员和成员函数

// 4. 公有成员函数

// 5. 内部类

// 6. 类外定义成员函数

// 7. 完善5和6!!!

#include <iostream>
#include <functional>
#include <list>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::getline;
using std::hash;
using std::istringstream;
using std::list;
using std::string;
using std::vector;

// hash 定义在头文件 <functional>
// 类模板
template <typename Key, typename Value, typename Hash = hash<Key>>
// HashTable类
class HashTable
{
private:
    // 前向声明
    class HashNode;

private:
    // 数据成员(5)+1+私有成员函数(2)
    // using 定义别名
    // 定义桶的类型为保存键值对的链表
    using Bucket = list<HashNode>;

    // 存储所有桶的动态数组
    vector<Bucket> buckets;

    // 哈希函数对象
    Hash hashFunction;

    // 哈希表的大小, 即桶的数量
    size_t tableSize;

    // 哈希表中元素的数量
    size_t numElements;

    // 默认最大负载因子
    float maxLoadFactor = 0.75;

    // 计算键的哈希值, 并将其映射到桶的索引
    size_t hashKey(const Key &key) const;

    // 当元素数量超过最大负载因子定义的容量时
    // 增加桶的数量并重新分配所有键
    void rehashAllKey(size_t newSize);

public:
    // 公有成员函数(8)
    // 构造函数初始化哈希表
    HashTable(size_t size = 10, const Hash &hashFunc = Hash());

    // 插入键值对到哈希表中
    void insertKeyValue(const Key &key, const Value &value);

    // 插入键到哈希表中
    void insertKey(const Key &key);

    // 从哈希表中移除键
    void eraseKey(const Key &key);

    // 查找键是否存在于哈希表中
    Value *findKey(const Key &key);

    // 获取哈希表中元素的数量
    size_t size() const;

    // 打印哈希表中所有元素
    void print() const;

    void clear();
};

// 内部类
template <typename Key, typename Value, typename Hash>
class HashTable<Key, Value, Hash>::HashNode
{
public:
    Key _key;
    Value _value;

    // 构造函数 1
    // explicit禁止隐性转换???
    explicit HashNode(const Key &key) : _key(key), _value() {}

    // 构造函数 2
    HashNode(const Key &key, const Value &value) : _key(key), _value(value) {}

    // 比较运算符重载
    bool operator==(const HashNode &other) const
    {
        return _key == other._key;
    }

    bool operator!=(const HashNode &other) const
    {
        return _key != other._key;
    }

    bool operator<(const HashNode &other) const
    {
        return _key < other._key;
    }

    bool operator>(const HashNode &other) const
    {
        return _key > other._key;
    }

    bool operator==(const Key &key_) const
    {
        return _key == key_;
    }

    void print() const
    {
        cout << _key << " " << _value << " ";
    }
};

// 计算键的哈希值, 并将其映射到桶的索引
template <typename Key, typename Value, typename Hash>
size_t HashTable<Key, Value, Hash>::hashKey(const Key &key) const
{
    return hashFunction(key) % tableSize;
}

// 当元素数量超过最大负载因子定义的容量时
// 增加桶的数量并重新分配所有键
template <typename Key, typename Value, typename Hash>
void HashTable<Key, Value, Hash>::rehashAllKey(size_t newSize)
{
    // 创建新桶
    vector<Bucket> newBuckets(newSize);
    // 遍历旧桶
    for (Bucket &bucket : buckets)
    {
        // 遍历桶中的键值对
        for (HashNode &hashNode : bucket)
        {
            // 为键计算新的索引
            size_t newIndex = hashFunction(hashNode._key) % newSize;
            // 将键添加到新桶中
            newBuckets[newIndex].push_back(hashNode);
        }
    }
    // std::move 定义在头文件 <utility>
    // 更新桶数据
    buckets = std::move(newBuckets);
    // 更新哈希表大小
    tableSize = newSize;
}

// 构造函数初始化哈希表
template <typename Key, typename Value, typename Hash>
HashTable<Key, Value, Hash>::HashTable(size_t size, const Hash &hashFunc)
    : buckets(size), hashFunction(hashFunc), tableSize(size), numElements(0) {}

// 插入键值对到哈希表中
template <typename Key, typename Value, typename Hash>
void HashTable<Key, Value, Hash>::insertKeyValue(const Key &key, const Value &value)
{
    // 检查是否需要重哈希
    if ((numElements + 1) > maxLoadFactor * tableSize)
    {
        // 处理clear后tableSize=0的情况
        if (tableSize == 0)
        {
            tableSize = 1;
        }
        // 否则重哈希 桶数量*2
        rehashAllKey(tableSize * 2);
    }
    // 计算键的索引
    size_t index = hashKey(key);
    // 获取对应的桶
    // list<HashNode>
    auto &bucket = buckets[index];
    // 如果键不在桶中 则添加到桶中
    // find 定义在头文件 <algorithm>
    auto it = find(bucket.begin(), bucket.end(), key);
    // 键不在桶中
    if (it == bucket.end())
    {
        bucket.push_back(HashNode(key, value));
        // 增加元素数量
        ++numElements;
    }
}

// 插入键到哈希表中
template <typename Key, typename Value, typename Hash>
void HashTable<Key, Value, Hash>::insertKey(const Key &key)
{
    insertKeyValue(key, Value{});
}

// 从哈希表中移除键
template <typename Key, typename Value, typename Hash>
void HashTable<Key, Value, Hash>::eraseKey(const Key &key)
{
    // 计算键的索引
    size_t index = hashKey(key);
    // 获取对应的桶
    auto &bucket = buckets[index];
    // 查找键
    auto it = find(bucket.begin(), bucket.end(), key);
    // 如果找到键
    if (it != bucket.end())
    {
        // 从桶中移除键
        bucket.erase(it);
        // 减少元素数量
        numElements--;
    }
}

// 查找键是否存在于哈希表中
template <typename Key, typename Value, typename Hash>
Value *HashTable<Key, Value, Hash>::findKey(const Key &key)
{
    // 计算键的索引
    size_t index = hashKey(key);
    // 获取对应的桶
    auto &bucket = buckets[index];
    // 返回键是否在桶中
    auto it = find(bucket.begin(), bucket.end(), key);
    if (it != bucket.end())
    {
        return &it->_value;
    };
    return nullptr;
}

// 获取哈希表中元素的数量
template <typename Key, typename Value, typename Hash>
size_t HashTable<Key, Value, Hash>::size() const
{
    return numElements;
}

// 打印哈希表中所有元素
template <typename Key, typename Value, typename Hash>
void HashTable<Key, Value, Hash>::print() const
{
    for (size_t i = 0; i < buckets.size(); i++)
    {
        for (const HashNode &hashNode : buckets[i])
        {
            hashNode.print();
        }
    }
}

template <typename Key, typename Value, typename Hash>
void HashTable<Key, Value, Hash>::clear()
{
    this->buckets.clear();
    this->tableSize = 0;
    this->numElements = 0;
}

int main()
{
    // 创建一个哈希表实例
    HashTable<int, int> hashTable;

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

        int key;
        int value;

        if (command == "insert")
        {
            iss >> key >> value;
            hashTable.insertKeyValue(key, value);
        }

        if (command == "erase")
        {
            if (hashTable.size() == 0)
            {
                continue;
            }
            iss >> key;
            hashTable.eraseKey(key);
        }

        if (command == "find")
        {
            if (hashTable.size() == 0)
            {
                cout << "not exist" << endl;
                continue;
            }
            iss >> key;
            int *res = hashTable.findKey(key);
            if (res != nullptr)
            {
                cout << *res << endl;
            }
            else
            {
                cout << "not exist" << endl;
            }
        }

        if (command == "print")
        {
            if (hashTable.size() == 0)
            {
                cout << "empty" << endl;
            }
            else
            {
                hashTable.print();
            }
        }

        if (command == "size")
        {
            cout << hashTable.size() << endl;
        }

        if (command == "clear")
        {
            hashTable.clear();
        }
    }
    return 0;
}