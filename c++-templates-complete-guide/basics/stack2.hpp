#ifndef STACK2_H
#define STACK2_H

#include "stack1.hpp"
#include <cassert>
#include <deque>
#include <iostream>
#include <string>

template <> class Stack<std::string> {
private:
  std::deque<std::string> elems;

public:
  void push(std::string const &);
  void pop();
  std::string const &top() const;
  bool empty() const { return elems.empty(); }
};

void Stack<std::string>::push(std::string const &elem) {
  std::cout << "push() specialized\n";
  elems.push_back(elem);
}

void Stack<std::string>::pop() {
  std::cout << "pop() specialized\n";
  assert(!elems.empty());
  elems.pop_back();
}

std::string const &Stack<std::string>::top() const {
  std::cout << "top() specialized\n";
  assert(!elems.empty());
  return elems.back();
}

#endif
