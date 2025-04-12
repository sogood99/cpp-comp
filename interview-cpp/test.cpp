#include <iostream>

int main() {
  auto s = "abc";
  std::cout << typeid(s).name() << std::endl;

  return 0;
}
