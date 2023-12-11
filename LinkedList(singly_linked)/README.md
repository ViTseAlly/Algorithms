# Linked List Implementation in C++

## Node Structure
The Node structure defines the building block of the linked list. It contains a character (current) and a pointer to the next node (next).
Two constructors are provided: a default constructor and a parameterized constructor that initializes the node with specific values.
```cpp
struct Node
{
  char current;
  Node* next;
  Node* prev;
  Node() : current(char()), next(nullptr), prev(nullptr) {}
  Node(Node* prevV, char curV, Node* nextV) : current(curV), next(nextV), prev(prevV) {}
};
```
## LinkedList Class
The LinkedList class encapsulates the linked list operations.
It has a default constructor that initializes the head node to nullptr.
The destructor is responsible for freeing memory by deleting all nodes in the linked list.
addNode method adds a new node with the given value to the end of the list.
getNodes method displays the characters stored in each node of the linked list.
```cpp
class LinkedList
{
public:
  LinkedList() : _nodes(nullptr) {}
  ~LinkedList();
  void setValue(char _value);
  void deleteValue();
  void deleteValue(char _value);
  void getList();

private:
  Node* _nodes;
};
```
## Destructor Implementation
The destructor iterates through each node in the linked list, deletes it, and moves to the next node until the end of the list is reached.

```cpp
LinkedList::~LinkedList()
{
  Node* current = _nodes;
  while (current != nullptr)
  {
    Node* next = current->next;
    delete current;
    current = next;
  }
}
```
## Method to Add a Node
addNode creates a new node with the given value and adds it to the end of the linked list.
```cpp
void LinkedList::setValue(char _value)
{
  Node* newNode = new Node(nullptr, _value, nullptr);
  if (_nodes == nullptr)
  {
    _nodes = newNode;
  }
  else
  {
    Node* current = _nodes;
    while (current->next != nullptr)
    {
      current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
  }
}
```
## Method to Display Nodes
getNodes traverses the linked list and prints the characters stored in each node to the standard output.
```cpp
void LinkedList::getList()
{
  Node* current = _nodes;
  while (current != nullptr)
  {
    std::cout << current->current << " ";
    current = current->next;
  }
}
```

## Delete last element
Method fing nullptr Node and delete them.
```cpp
void LinkedList::deleteValue()
{
  if (_nodes == nullptr)
  {
    return;
  }

  Node* current = _nodes;
  while (current->next != nullptr)
  {
    current = current->next;
  }

  if (current->prev != nullptr)
  {
    current->prev->next = nullptr; 
  }
  else
  {
    _nodes = nullptr; 
  }

  delete current;
}
```

##Delete node by value
Method fing valie and deleted node, displacing the remaining nodes that followed it
```cpp
void LinkedList::deleteValue(char _value)
{
  Node* current = _nodes;
  while (current != nullptr && current->current != _value)
  {
    current = current->next;
  }

  if (current == nullptr)
  {
    std::cout << "Value not found in the list" << std::endl;
    return;
  }

  if (current->prev != nullptr)
  {
    current->prev->next = current->next;
  }
  else
  {
    _nodes = current->next;
  }

  if (current->next != nullptr)
  {
    current->next->prev = current->prev;
  }

  delete current;
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
