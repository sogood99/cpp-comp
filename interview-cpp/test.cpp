#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3};

  v.erase(v.begin(), v.end());

  std::cout << v.size() << std::endl;
}
