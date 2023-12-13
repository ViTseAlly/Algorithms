#include <iostream>
#include <string>
#include <functional>
#include <memory>


template <typename Key, typename Value>
class HashTable {
public:
  HashTable(size_t size = 8) : hash_size(size), hashmap(new Node *[size]{}), size(0) {}
  HashTable(const HashTable &) = delete;
  HashTable &operator=(const HashTable &) = delete;
  ~HashTable() { Clear(); }

  void Clear() {
    for (size_t i = 0; i < hash_size; ++i) {
      Node *current = this->hashmap[i];
      while (current != nullptr) {
        Node *temp = current->next.get();
        delete current;
        current = temp;
      }
    }
    delete[] this->hashmap;
  }

  void push_back(const Key &key, const Value &value) {
    size_t index = HashingFunction(key);
    Node *&node = this->hashmap[index];

    Node *current = node;
    while (current != nullptr) {
      if (current->key == key) {
        current->value = value;
        return;
      }
      current = current->next.get();
    }

    node = new Node{key, value, nullptr, node};
    size++;
  }

  Value &getValue(const Key &key) {
    size_t index = HashingFunction(key);
    Node *node = this->hashmap[index];
    while (node != nullptr && key != node->key) {
      node = node->next.get();
    }

    if (node == nullptr) {
      throw std::out_of_range("Key not found");
    }

    return node->value;
  }




private:
  struct Node {
    Key key;
    Value value;
    std::unique_ptr<Node> next;
    Node(Key k, Value v, std::unique_ptr<Node> n, Node *prev) : key(k), value(v), next(std::move(n)) {
      if (prev != nullptr) {
        prev->next = std::unique_ptr<Node>(this);
      }
    }
  };

  size_t hash_size;
  Node **hashmap;
  size_t size;

  size_t HashingFunction(const Key &key) {
    return std::hash<Key>()(key) % (hash_size);
  }
};

int main() {
  HashTable<std::string, int> myTable;

  myTable.push_back("one", 1);
  myTable.push_back("two", 2);
  myTable.push_back("three", 3);

  try {
    std::cout << "Value for key 'two': " << myTable.getValue("two") << std::endl;
  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
