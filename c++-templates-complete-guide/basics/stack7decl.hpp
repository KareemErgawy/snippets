#ifndef STACK7DECL_H
#define STACK7DECL_H

#include <cassert>
#include <deque>

template <typename T, typename Cont = std::deque<T>> class Stack {
private:
  Cont elems;

public:
  void push(T const &elem);
  void pop();
  T const &top() const;
  bool empty() const { return elems.empty(); }

  template <typename T2, typename Cont2>
  Stack &operator=(Stack<T2, Cont2> const &);

  template <typename, typename> friend class Stack;
};

template <typename T, typename Cont> void Stack<T, Cont>::push(T const &elem) {
  elems.push_back(elem);
}

template <typename T, typename Cont> void Stack<T, Cont>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T, typename Cont> T const &Stack<T, Cont>::top() const {
  assert(!elems.empty());
  return elems.back();
}

template <typename T, typename Cont>
template <typename T2, typename Cont2>
Stack<T, Cont> &Stack<T, Cont>::operator=(Stack<T2, Cont2> const &op2) {
  Stack<T2, Cont2> tmp(op2);

  elems.clear();
  elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());

  return *this;
}

#endif
