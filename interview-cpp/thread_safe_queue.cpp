#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

template <typename T> class Queue {
public:
  void pop(T &item) {
    std::unique_lock<std::mutex> mlock(_m);
    _c.wait(mlock, [&] { return !_q.empty(); });
    item = _q.front();
    _q.pop();
  }

  void push(const T &item) {
    std::unique_lock<std::mutex> mlock(_m);
    _q.push(item);

    mlock.unlock();
    _c.notify_one();
  }

private:
  std::mutex _m;
  std::queue<T> _q;
  std::condition_variable _c;
};

std::mutex printLock;

void pushRun(Queue<int> &q, int i) {
  q.push(i);
  std::unique_lock<std::mutex> mlock(printLock);
  std::cout << "Pushed " << i << std::endl;
}

void popRun(Queue<int> &q) {
  int a;
  q.pop(a);
  std::unique_lock<std::mutex> mlock(printLock);
  std::cout << "Popped " << a << std::endl;
}

int main() {
  int n = 10;
  std::vector<std::thread> v;
  Queue<int> q;
  for (int i = 0; i < n; i++) {
    v.push_back(std::thread(pushRun, std::ref(q), i));
  }

  for (int i = 0; i < n; i++) {
    v.push_back(std::thread(popRun, std::ref(q)));
  }

  for (auto &t : v) {
    t.join();
  }

  return 0;
}
