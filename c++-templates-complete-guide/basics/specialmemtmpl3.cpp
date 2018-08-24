#include <iostream>
#include <string>
#include <utility>

template <typename T>
using EnableIfString =
    typename std::enable_if<std::is_convertible<T, std::string>::value>::type;

class Person {
private:
  std::string name;

public:
  template <typename STR, typename = EnableIfString<STR>>
  explicit Person(STR &&n) : name(std::forward<STR>(n)) {
    std::cout << "forwarding string-cstor for '" << name << "'\n";
  }

  Person(Person const &p) : name(p.name) {
    std::cout << "copy-cstor for '" << name << "'\n";
  }

  Person(Person &&p) : name(std::move(p.name)) {
    std::cout << "move-cstor for '" << name << "'\n";
  }
};

int main() {
  std::string s = "sname";
  Person p1(s);
  Person p2("tmp");
  Person p3(p1);
  Person p4(std::move(p1));
  Person const p2c("ctmp");
  Person p3c(p2c);
  return 0;
}
