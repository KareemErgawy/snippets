#ifndef ADDSPACE_H
#define ADDSPACE_H

#include <iostream>

template <typename T> class AddSpace {
private:
  T const &ref;

public:
  AddSpace(T const &r) : ref(r) {}

  friend std::ostream &operator<<(std::ostream &os, AddSpace<T> s) {
    return os << s.ref << ' ';
  }
};

template <typename... Args> void print(Args... args) {
  // Fold expression.
  (std::cout << ... << AddSpace(args)) << '\n';
}
#endif
