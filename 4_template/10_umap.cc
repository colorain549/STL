#include "hashTable.h"
#include <cstddef>

template <typename Key, typename Value>
class Unordered_map
{
private:
    HashTable<Key, Value> hashtable;

public:
    Unordered_map() : hashtable() {};

    ~Unordered_map() {}

    bool empty() const noexcept;

    size_t size() const noexcept;

    void clear() noexcept;

    void insert(const Key &key, const Value &value);

    void erase(const Key &key);

    bool find(const Key &key);

    Value &operator[](const Key &key);
};

template <typename Key, typename Value>
bool Unordered_map<Key, Value>::empty() const noexcept
{
    return hashtable.size() == 0;
}

template <typename Key, typename Value>
size_t Unordered_map<Key, Value>::size() const noexcept
{
    return hashtable.size();
}

template <typename Key, typename Value>
void Unordered_map<Key, Value>::clear() noexcept
{
    hashtable.clear();
}

template <typename Key, typename Value>
void Unordered_map<Key, Value>::insert(const Key &key, const Value &value)
{
    hashtable.insertKeyValue(key, value);
}

template <typename Key, typename Value>
void Unordered_map<Key, Value>::erase(const Key &key)
{
    hashtable.eraseKey(key);
}

template <typename Key, typename Value>
bool Unordered_map<Key, Value>::find(const Key &key)
{
    return hashtable.findKey(key) != nullptr;
}

template <typename Key, typename Value>
Value &Unordered_map<Key, Value>::operator[](const Key &key)
{
    Value *ans = hashtable.findKey(key);
    if (ans != nullptr)
    {
        return *ans;
    }
    hashtable.insertKey(key);
    ans = hashtable.findKey(key);
    return *ans;
}

int main()
{
    Unordered_map<int, int> map;

    int N;
    std::cin >> N;
    getchar();

    std::string line;

    for (int i = 0; i < N; i++)
    {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        int key;
        int value;

        if (command == "insert")
        {
            iss >> key >> value;
            map.insert(key, value);
        }

        if (command == "erase")
        {
            iss >> key;
            map.erase(key);
        }

        if (command == "find")
        {
            iss >> key;
            if (map.find(key))
            {
                std::cout << "true" << std::endl;
            }
            else
            {
                std::cout << "false" << std::endl;
            }
        }

        // size 命令
        if (command == "size")
        {
            std::cout << map.size() << std::endl;
        }

        // empty 命令
        if (command == "empty")
        {
            if (map.empty())
            {
                std::cout << "true" << std::endl;
            }
            else
            {
                std::cout << "false" << std::endl;
            }
        }
    }
    return 0;
}