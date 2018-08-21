#include <iostream>

template <typename T1, typename T2> constexpr auto max(T1 a, T2 b) {
  return b < a ? a : b;
}

int main() {
  constexpr auto size = ::max(100, 50);
  int array[size];
  std::cout << size << std::endl;

  return 0;
}
