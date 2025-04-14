#include <iostream>
#include <type_traits>

int main() {

  auto s = "Hello, World!";

  std::cout << std::is_same_v<decltype("Hello, World!"), decltype(s)>;

  return 0;
}
