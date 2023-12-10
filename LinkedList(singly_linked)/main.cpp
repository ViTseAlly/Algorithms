#include <iostream>

struct Node {
    char current;
    Node* next;
    Node() {};
    Node(char curV, Node* nextV) : current(curV), next(nextV) {};
};

class LinkedList {
public:
    LinkedList() : node(nullptr) {};
    ~LinkedList();
    void addNode(char value);
    void getNodes();
private:
    Node* node;
};

LinkedList::~LinkedList() {
    Node* current = node;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::addNode(char value) {
    Node* cur = new Node(value, nullptr);
    if (node == nullptr) node = cur;
    else {
        Node* current = node;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = cur;
    }
}

void LinkedList::getNodes() {
    Node* value = node;
    while (value != nullptr) {
        std::cout << value->current;
        value = value->next;
    }
}

int main() {
    LinkedList linkedList;
    linkedList.addNode('H');
    linkedList.addNode('e');
    linkedList.addNode('l');
    linkedList.addNode('l');
    linkedList.addNode('o');
    linkedList.addNode(' ');
    linkedList.addNode('w');
    linkedList.addNode('o');
    linkedList.addNode('r');
    linkedList.addNode('l');
    linkedList.addNode('d');
    linkedList.addNode('!');

    linkedList.getNodes();
    return 0;
}
