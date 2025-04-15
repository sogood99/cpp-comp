#include <iostream>

struct mutex {
  void Lock() { std::cout << "locked" << std::endl; }
  void Unlock() { std::cout << "unlocked" << std::endl; }
};

// RAII
class LockGuard {
private:
  mutex &m;

public:
  LockGuard(mutex &m) : m(m) { m.Lock(); }
  ~LockGuard() { m.Unlock(); }
  LockGuard(const LockGuard &other) = delete;
  LockGuard operator=(const LockGuard &other) = delete;
  LockGuard(LockGuard &&other) noexcept = delete;
  LockGuard operator=(LockGuard &&other) noexcept = delete;
};

int main() {
  mutex m;
  {
    LockGuard l(m);

    std::cout << "Do stuff" << std::endl;
  }

  return 0;
}
