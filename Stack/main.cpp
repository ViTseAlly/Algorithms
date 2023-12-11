#include <iostream>

class Stack
{
public:
  Stack() : __stack(nullptr), __size(0), __capacity(0) {};
  ~Stack() { if (__stack != nullptr) delete[] __stack; };

  void push_stack(char value);
  void pop_stack();
  void get_stack();
private:
  char* __stack;
  size_t __size;
  size_t __capacity;

  void updateMemory();
};

void Stack::push_stack(char value)
{
  if (__size == __capacity) updateMemory();
  __stack[__size++] = value;
}

void Stack::pop_stack()
{
  if (__size == 0) return;
  --__size;
}


void Stack::get_stack()
{
  for (size_t i = 0; i < __size; ++i)
  {
    std::cout << __stack[i] << std::endl;
  }
}

void Stack::updateMemory()
{
  size_t new_capacity = (__capacity == 0) ? 1 : __capacity * 2;
  char* new_stack = new char[new_capacity];

  for (size_t i = 0; i < __size; ++i)
  {
    new_stack[i] = __stack[i];
  }

  delete[] __stack;
  __stack = new_stack;
  __capacity = new_capacity;
}


int main()
{
  Stack st;
  st.push_stack('H');
  st.push_stack('e');
  st.push_stack('l');
  st.push_stack('l');
  st.push_stack('o');
  st.push_stack(' ');
  st.push_stack('w');
  st.push_stack('o');
  st.push_stack('r');
  st.push_stack('l');
  st.push_stack('d');
  st.push_stack('!');
  st.pop_stack();
  st.pop_stack();
  st.get_stack();

  return 0;
}f
