#ifndef STACK1_H
#define STACK1_H

#include <cassert>
#include <iostream>
#include <vector>

template <typename T> class Stack {
private:
  std::vector<T> elems;

public:
  void push(T const &elem);
  void pop();
  T const &top() const;
  bool empty() const { return elems.empty(); }
};

template <typename T> void Stack<T>::push(T const &elem) {
  std::cout << "push() general\n";
  elems.push_back(elem);
}

template <typename T> void Stack<T>::pop() {
  std::cout << "pop() general\n";
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T> T const &Stack<T>::top() const {
  std::cout << "top() general\n";
  assert(!elems.empty());
  return elems.back();
}

#endif
