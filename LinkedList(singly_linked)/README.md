# Linked List Implementation in C++

## Node Structure
The Node structure defines the building block of the linked list. It contains a character (current) and a pointer to the next node (next).
Two constructors are provided: a default constructor and a parameterized constructor that initializes the node with specific values.
```cpp
struct Node {
    char current;    // Data of the node
    Node* next;      // Pointer to the next node

    // Constructors for the Node structure
    Node() {};                           // Default constructor
    Node(char curV, Node* nextV) : current(curV), next(nextV) {};  // Parameterized constructor
};
```
## LinkedList Class
The LinkedList class encapsulates the linked list operations.
It has a default constructor that initializes the head node to nullptr.
The destructor is responsible for freeing memory by deleting all nodes in the linked list.
addNode method adds a new node with the given value to the end of the list.
getNodes method displays the characters stored in each node of the linked list.
```cpp
class LinkedL
ist {
public:
    // Constructors and destructor
    LinkedList() : node(nullptr) {};
    ~LinkedList();
    
    // Method to add a node to the linked list
    void addNode(char value);
    
    // Method to display all nodes in the linked list
    void getNodes();

private:
    Node* node;    // Head node of the linked list
};
```
## Destructor Implementation
The destructor iterates through each node in the linked list, deletes it, and moves to the next node until the end of the list is reached.

```cpp
LinkedList::~LinkedList() {
    Node* current = node;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
```
## Method to Add a Node
addNode creates a new node with the given value and adds it to the end of the linked list.
```cpp
void LinkedList::addNode(char value) {
    Node* cur = new Node(value, nullptr);
    if (node == nullptr) 
        node = cur;
    else {
        Node* current = node;
        while (current->next != nullptr) 
            current = current->next;
        current->next = cur;
    }
}
```
## Method to Display Nodes
getNodes traverses the linked list and prints the characters stored in each node to the standard output.
```cpp
void LinkedList::getNodes() {
    Node* value = node;
    while (value != nullptr) {
        std::cout << value->current;
        value = value->next;
    }
}
```

## Main Function
The main function demonstrates the usage of the LinkedList class by creating an instance, adding nodes with characters, and then displaying the characters in the linked list.
```cpp
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
```
