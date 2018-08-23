#include "boolstring.hpp"
#include <iostream>

int main() {

  std::cout << std::boolalpha;
  BoolString s1("Hello");
  std::cout << s1.get() << '\n';
  std::cout << s1.get<bool>() << '\n';
  BoolString s2("on");
  std::cout << s2.get() << '\n';
  std::cout << s2.get<bool>() << '\n';

  return 0;
}
