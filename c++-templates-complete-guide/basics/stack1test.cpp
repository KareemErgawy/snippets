#include "stack1.hpp"
#include "stack2.hpp"
#include "stackpartspec.hpp"
#include <iostream>
#include <string>

int main() {
  Stack<int> intStack;
  Stack<std::string> stringStack;

  intStack.push(7);
  std::cout << intStack.top() << "\n";

  stringStack.push("hello");
  std::cout << stringStack.top() << "\n";
  stringStack.pop();

  Stack<int *> ptrStack;
  ptrStack.push(new int{42});

  std::cout << *ptrStack.top() << "\n";
  delete ptrStack.pop();

  return 0;
}
