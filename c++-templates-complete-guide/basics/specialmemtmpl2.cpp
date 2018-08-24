#include <iostream>
#include <string>
#include <utility>

class Person {
private:
  std::string name;

public:
  template <typename STR>
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
  // Compile error. The template construction is chosen and STR is substituted
  // by Person. The copy construction from Person is however not chosen because
  // a conversion to const is needed.
  // Person p3(p1);
  Person p4(std::move(p1));
  Person const p2c("ctmp");
  Person p3c(p2c);
  return 0;
}
