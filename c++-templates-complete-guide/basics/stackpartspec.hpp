#ifndef STACKPARTSPEC_H
#define STACKPARTSPEC_H

#include "stack1.hpp"

template <typename T> class Stack<T *> {
private:
  std::vector<T *> elems;

public:
  void push(T *);
  T *pop();
  T *top() const;
  bool empty() const { return elems.empty(); }
};

template <typename T> void Stack<T *>::push(T *elem) {
  std::cout << "push() partially-specialized\n";
  elems.push_back(elem);
}

template <typename T> T *Stack<T *>::pop() {
  std::cout << "pop() partially-specialized\n";
  assert(!elems.empty());
  T *p = elems.back();
  elems.pop_back();
  return p;
}

template <typename T> T *Stack<T *>::top() const {
  std::cout << "top() partially-specialized\n";
  assert(!elems.empty());
  return elems.back();
}

#endif
