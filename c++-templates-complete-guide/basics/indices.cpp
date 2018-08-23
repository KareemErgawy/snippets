#include <array>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

template <std::size_t... Idx, typename T> void printByIdx(T t) {
  (std::cout << ... << t[Idx]) << '\n';
}

int main() {
  std::vector<std::string> arr = {"Hello", "there", "world"};
  printByIdx<0, 1, 2>(arr);

  return 0;
}
