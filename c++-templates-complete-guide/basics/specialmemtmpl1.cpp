#include <iostream>
#include <string>
#include <utility>

class Person {
private:
  std::string name;

public:
  explicit Person(std::string const &n) : name(n) {
    std::cout << "copying string-cstor for '" << name << "'\n";
  }

  explicit Person(std::string &&n) : name(std::move(n)) {
    std::cout << "moving string-cstor for '" << name << "'\n";
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
  return 0;
}
