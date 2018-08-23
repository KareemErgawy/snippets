#ifndef STACK6DECL_H
#define STACK6DECL_H

#include <cassert>
#include <deque>

template <typename T> class Stack {
private:
  std::deque<T> elems;

public:
  void push(T const &elem);
  void pop();
  T const &top() const;
  bool empty() const { return elems.empty(); }

  template <typename T2> Stack &operator=(Stack<T2> const &);

  template <typename> friend class Stack;
};

template <typename T> void Stack<T, Cont>::push(T const &elem) {
  elems.push_back(elem);
}

template <typename T> void Stack<T, Cont>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T> T const &Stack<T, Cont>::top() const {
  assert(!elems.empty());
  return elems.back();
}

template <typename T>
template <typename T2>
Stack<T> &Stack<T>::operator=<T2>(Stack<T2> const &op2) {
  Stack<T2> tmp(op2);

  elems.clear();
  elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());

  return *this;
}

#endif
