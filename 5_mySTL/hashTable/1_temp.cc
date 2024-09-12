// 1. 类模版 + HashTable类
// 2. HashNode类 + 私有前向声明
// 3. 私有数据成员和成员函数

#include <iostream>
#include <functional>
#include <list>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::hash;
using std::list;
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
};

int main()
{
    return 0;
}