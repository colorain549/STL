// https://kamacoder.com/problempage.php?pid=1162&cid=10&lid=111
// 
#include "hashTable.h"
#include <cstddef>

template <typename Key>
class Unordered_set
{
public:
    Unordered_set() : hashtable() {};

    ~Unordered_set() {}

    bool empty() const noexcept;

    size_t size() const noexcept;

    void clear() noexcept;

    void insert(Key key);

    void erase(Key key);

    bool find(const Key &key);

private:
    HashTable<Key, Key> hashtable;
};

template <typename Key>
bool Unordered_set<Key>::empty() const noexcept
{
    return hashtable.size() == 0;
}

template <typename Key>
size_t Unordered_set<Key>::size() const noexcept
{
    return hashtable.size();
}

template <typename Key>
void Unordered_set<Key>::clear() noexcept
{
    hashtable.clear();
}

template <typename Key>
void Unordered_set<Key>::insert(Key key)
{
    hashtable.insertKey(key);
}

template <typename Key>
void Unordered_set<Key>::erase(Key key)
{
    hashtable.eraseKey(key);
}

template <typename Key>
bool Unordered_set<Key>::find(const Key &key)
{
    return hashtable.findKey(key) != nullptr;
}

int main()
{
    Unordered_set<int> mySet;
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

        int element;

        if (command == "insert")
        {
            iss >> element;
            mySet.insert(element);
        }

        if (command == "erase")
        {
            iss >> element;
            mySet.erase(element);
        }

        if (command == "find")
        {
            iss >> element;
            std::cout << (mySet.find(element) ? "true" : "false") << std::endl;
        }

        if (command == "size")
        {
            std::cout << mySet.size() << std::endl;
        }

        if (command == "empty")
        {
            std::cout << (mySet.empty() ? "true" : "false") << std::endl;
        }
    }
    return 0;
}