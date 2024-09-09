#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::getline;
using std::hash;
using std::istringstream;
using std::list;
using std::move;
using std::string;
using std::vector;

// hash 定义在头文件 <functional>
template <typename Key, typename Value, typename Hash = hash<Key>>
class HashTable
{
    class HashNode
    {
    public:
        Key _key;
        Value _value;

        // 从Key构造节点，Value使用默认构造
        explicit HashNode(const Key &key) : _key(key), _value() {}

        // 从Key和Value构造节点
        HashNode(const Key &key, const Value &value) : _key(key), _value(value) {}

        // 比较运算符重载，只按照key进行比较
        bool operator==(const HashNode &other) const { return _key == other._key; }

        bool operator!=(const HashNode &other) const { return _key != other._key; }

        bool operator<(const HashNode &other) const { return _key < other._key; }

        bool operator>(const HashNode &other) const { return _key > other._key; }

        bool operator==(const Key &key_) const { return _key == key_; }

        void print() const
        {
            cout << _key << " " << _value << " ";
        }
    };

private:
    // 定义桶的类型为存储键的链表
    using Bucket = list<HashNode>;
    // 存储所有桶的动态数组
    vector<Bucket> buckets;
    // 哈希函数对象
    Hash hashFunction;
    // 哈希表的大小，即桶的数量
    size_t tableSize;
    // 哈希表中元素的数量
    size_t numElements;

    // 默认的最大负载因子
    float maxLoadFactor = 0.75;

    // 计算键的哈希值，并将其映射到桶的索引
    size_t hash(const Key &key) const { return hashFunction(key) % tableSize; }

    // 当元素数量超过最大负载因子定义的容量时，增加桶的数量并重新分配所有键
    void rehash(size_t newSize)
    {
        // 创建新的桶数组
        vector<Bucket> newBuckets(newSize);
        // 遍历旧桶
        for (Bucket &bucket : buckets)
        {
            // 遍历桶中的每个键
            for (HashNode &hashNode : bucket)
            {
                // 为键计算新的索引
                size_t newIndex = hashFunction(hashNode._key) % newSize;
                // 将键添加到新桶中
                newBuckets[newIndex].push_back(hashNode);
            }
        }
        // 定义在头文件<utility>
        // 使用移动语义更新桶数组
        buckets = move(newBuckets);
        // 更新哈希表大小
        tableSize = newSize;
    }

public:
    // 构造函数初始化哈希表
    HashTable(size_t size = 10, const Hash &hashFunc = Hash())
        : buckets(size), hashFunction(hashFunc), tableSize(size), numElements(0) {}

    // 插入键到哈希表中
    void insert(const Key &key, const Value &value)
    {
        // 检查是否需要重哈希
        if ((numElements + 1) > maxLoadFactor * tableSize)
        {
            // 处理 clear 后再次插入元素时 tableSize = 0 的情况
            if (tableSize == 0)
                tableSize = 1;
            // 重哈希，桶数量翻倍
            rehash(tableSize * 2);
        }
        // 计算键的索引
        size_t index = hash(key);
        // 获取对应的桶
        list<HashNode> &bucket = buckets[index];
        // 如果键不在桶中，则添加到桶中
        if (find(bucket.begin(), bucket.end(), key) == bucket.end())
        {
            bucket.push_back(HashNode(key, value));
            // 增加元素数量
            ++numElements;
        }
    }

    void insertKey(const Key &key) { insert(key, Value{}); }

    // 从哈希表中移除键
    void erase(const Key &key)
    {
        // 计算键的索引
        size_t index = hash(key);
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
    Value *findKey(const Key &key)
    {
        // 计算键的索引
        size_t index = hash(key);
        // 获取对应的桶
        auto &bucket = buckets[index];
        // 返回键是否在桶中
        auto ans = find(bucket.begin(), bucket.end(), key);
        if (ans != bucket.end())
        {
            return &ans->_value;
        };
        return nullptr;
    }

    // 获取哈希表中元素的数量
    size_t size() const { return numElements; }

    // 打印哈希表中的所有元素
    void print() const
    {
        for (size_t i = 0; i < buckets.size(); ++i)
        {
            for (const HashNode &element : buckets[i])
            {
                element.print();
            }
        }
        cout << endl;
    }
    void clear()
    {
        this->buckets.clear();
        this->numElements = 0;
        this->tableSize = 0;
    }
};

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
            hashTable.insert(key, value);
        }

        if (command == "erase")
        {
            if (hashTable.size() == 0)
            {
                continue;
            }
            iss >> key;
            hashTable.erase(key);
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