#ifndef STACK9_H
#define STACK9_H

#include <cassert>
#include <deque>
#include <iostream>
#include <memory>

template <typename T, template <typename Elem, typename = std::allocator<Elem>>
                      class Cont = std::deque>
class Stack {
private:
  Cont<T> elems;

public:
  void push(T const &elem);
  void pop();
  T const &top() const;
  bool empty() const { return elems.empty(); }

  template <typename T2,
            template <typename Elem2, typename = std::allocator<Elem2>>
            class Cont2>
  Stack<T, Cont> &operator=(Stack<T2, Cont2> const &op2);

  template <typename, template <typename, typename> class> friend class Stack;
};

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::push(T const &elem) {
  elems.push_back(elem);
}

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T, template <typename, typename> class Cont>
T const &Stack<T, Cont>::top() const {
  assert(!elems.empty());
  return elems.back();
}

template <typename T, template <typename, typename> class Cont>
template <typename T2, template <typename, typename> class Cont2>
Stack<T, Cont> &Stack<T, Cont>::operator=(Stack<T2, Cont2> const &op2) {
  // No need to do a tmp copy here. Assignments between objects of the same
  // template instance go through the default operator=(). This one is used only
  // when the types differ.
  std::cout << "Heterogenous assignment operator\n";
  elems.clear();
  elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());

  return *this;
}

#endif
