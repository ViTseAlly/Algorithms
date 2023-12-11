#include <iostream>

struct Node
{
  char current;
  Node* next;
  Node* prev;
  Node() : current(char()), next(nullptr), prev(nullptr) {}
  Node(Node* prevV, char curV, Node* nextV) : current(curV), next(nextV), prev(prevV) {}
};

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

void LinkedList::getList()
{
  Node* current = _nodes;
  while (current != nullptr)
  {
    std::cout << current->current << " ";
    current = current->next;
  }
}

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

int main()
{
  LinkedList li;
  li.setValue('H');
  li.setValue('e');
  li.setValue('l');
  li.setValue('l');
  li.setValue('o');
  li.setValue(' ');
  li.setValue('w');
  li.setValue('o');
  li.setValue('r');
  li.setValue('l');
  li.setValue('d');
  li.setValue('!');
  li.deleteValue();
  li.deleteValue();
  li.deleteValue();
  li.deleteValue();
  li.deleteValue('l');
  li.getList();

  return 0;
}
