#ifndef STACK8DECL_H
#define STACK8DECL_H

#include <cassert>
#include <vector>

// Now you can type Stack<int, vector> instread of Stack<int, vector<int>>
template <typename T, template <typename /*[optional] ->*/ Elem>
                      typename /*class before C++17*/ Cont = std::deque>
class Stack {
private:
  Cont<T> elems;

public:
  void push(T const &elem);
  void pop();
  T const &top() const;
  bool empty() const { return elems.empty(); }
};

template <typename T, template <typename> typename Cont>
void Stack<T, Cont>::push(T const &elem) {
  elems.push_back(elem);
}

template <typename T, template <typename> typename Cont>
void Stack<T, Cont>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T, template <typename> typename Cont>
T const &Stack<T, Cont>::top() const {
  assert(!elems.empty());
  return elems.back();
}

#endif
