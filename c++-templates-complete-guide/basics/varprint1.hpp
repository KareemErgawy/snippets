#ifndef VARPRINT1_H
#define VARPRINT1_H

#include <iostream>

void print() {}

template <typename T, typename... Types> void print(T firstArg, Types... args) {
  std::cout << firstArg << '\n';
  std::cout << "Stil to print: " << sizeof...(Types) << "\n";
  print(args...);
}

#endif
