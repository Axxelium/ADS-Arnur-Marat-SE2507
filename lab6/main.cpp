#include <iostream>
#include <list>
#include <string>
#include <stdexcept>

// Hash table using separate chaining
template<typename K, typename V>
class HashTable {
private:
    static const int CAPACITY = 16;
    std::list<std::pair<K, V>> table[CAPACITY];
    int size_;

    int hash(const K& key) const {
        return std::hash<K>{}(key) % CAPACITY;
    }

public:
    HashTable() : size_(0) {}

    void insert(const K& key, const V& value) {
        int idx = hash(key);
        for (auto& pair : table[idx]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[idx].push_back({key, value});
        ++size_;
    }

    bool get(const K& key, V& value) const {
        int idx = hash(key);
        for (const auto& pair : table[idx]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    bool remove(const K& key) {
        int idx = hash(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (it->first == key) {
                table[idx].erase(it);
                --size_;
                return true;
            }
        }
        return false;
    }

    bool contains(const K& key) const {
        int idx = hash(key);
        for (const auto& pair : table[idx]) {
            if (pair.first == key) return true;
        }
        return false;
    }

    int size() const { return size_; }
};

int main() {
    HashTable<std::string, int> ht;

    ht.insert("apple",  5);
    ht.insert("banana", 3);
    ht.insert("cherry", 8);

    int val;
    if (ht.get("banana", val)) {
        std::cout << "banana -> " << val << "\n";
    }

    std::cout << "contains apple:  " << (ht.contains("apple")  ? "yes" : "no") << "\n";
    std::cout << "contains mango:  " << (ht.contains("mango")  ? "yes" : "no") << "\n";

    ht.remove("apple");
    std::cout << "after remove apple, contains apple: " << (ht.contains("apple") ? "yes" : "no") << "\n";
    std::cout << "size: " << ht.size() << "\n";

    return 0;
}
