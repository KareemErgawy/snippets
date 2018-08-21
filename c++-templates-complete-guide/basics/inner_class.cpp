#include <iostream>

int main() {
  class C {
  public:
    int iI;
  };

  C c;
  c.iI = 1;

  std::cout << c.iI << std::endl;
  return 0;
}
