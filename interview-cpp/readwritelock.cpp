#include <condition_variable>
#include <iostream>
#include <mutex>

class RWLock {
private:
  std::mutex _lock;
  std::condition_variable _cr, _cw;
  int reader = 0;
  int queued_writer = 0;
  bool writer = false;

public:
  void readLock() {
    std::unique_lock<std::mutex> mlock(_lock);
    _cr.wait(mlock, [this] { return !writer && queued_writer == 0; });
    reader++;
    mlock.unlock();
  }

  void readUnlock() {
    std::unique_lock<std::mutex> mlock(_lock);
    reader--;

    if (reader == 0 && queued_writer > 0) {
      mlock.unlock();
      _cw.notify_one();
    }
  }

  void writerLock() {
    std::unique_lock<std::mutex> mlock(_lock);
    _cw.wait(mlock, [this] { return !writer && reader == 0; });
    writer = true;
  }

  void writeUnlock() {
    std::unique_lock<std::mutex> mlock(_lock);
    writer = false;
    if (queued_writer > 0) {
      mlock.unlock();
      _cw.notify_one();
    } else {
      mlock.unlock();
      _cr.notify_all();
    }
  }
};

int main() { return 0; }
