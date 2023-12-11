//        Creating methods:
//          1. Adding element in queue;
//          2. Deleting element with queue;
//          3. Getting top element;
//          4. Getting size;
//          5. Print all elements in queue;
//          6. Constructor & Destructor;

#include <iostream>


struct Node
{
  char current;
  Node* next;
  Node(): current(char()), next(nullptr) {};
  Node(char value): current(value), next(nullptr) {};
};

class Queue
{
public:
  Queue(): __queue(nullptr) {};
  ~Queue();
  void enqueue(char value);
  void dequeue();
  void clear();
  bool isEmpty();
  char getTop();
  int getSize();
  void getAllQueue();

private:
  Node* __queue;
};


Queue::~Queue()
{
  Node* current = __queue;
  while(current != nullptr)
  {
    Node* next = current->next;
    delete current;
    current = next;
  }
}


void Queue::enqueue(char value)
{
    Node* newNode = new Node(value);
    if (__queue == nullptr)
    {
        __queue = newNode;
    } else
    {
        Node* current = __queue;
        while (current->next != nullptr) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
}


void Queue::dequeue()
{
  Node* nextNode = __queue->next;
  delete __queue;
  __queue = nextNode;
}


void Queue::clear()
{
  Node* current = __queue;
  while(current != nullptr)
  {
    Node* next = current->next;
    delete current;
    current = next;
  }
}


int Queue::getSize()
{
    int counter = 0;
    Node* current = __queue;
    while (current != nullptr) 
    {
        counter += 1;
        current = current->next;
    }
    return counter;
}


bool Queue::isEmpty()
{
  return __queue == nullptr;
}


char Queue::getTop()
{
    if (__queue != nullptr) 
    {
        return __queue->current;
    } else 
    {
        throw std::out_of_range("Queue is empty");
    }
}


void Queue::getAllQueue()
{
  Node* current = __queue;
  while(current != nullptr)
  {
    std::cout << current->current;
    current = current->next;
  }
  std::cout << std::endl;
}


int main()
{
    Queue q;
    q.enqueue('H');
    q.enqueue('e');
    q.enqueue('l');
    q.enqueue('l');
    q.enqueue('o');
    q.enqueue(' ');
    q.enqueue('w');
    q.enqueue('o');
    q.enqueue('r');
    q.enqueue('l');
    q.enqueue('d');
    q.enqueue('!');
    q.getAllQueue();

    std::cout << "Queue size: " << q.getSize() << std::endl;
    std::cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Top element: " << q.getTop() << std::endl;

    return 0;
}
