#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <set>

using namespace std;

struct LL {
  int pos;
  LL *next;
};

int main() {
  int n;
  cin >> n;
  LL **arr = new LL *[n + 1];
  for (int i = 0; i < n + 1; i++) {
    arr[i] = nullptr;
  }

  multiset<int, greater<int>> bbt;

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    LL *node = new LL;
    node->pos = i;
    node->next = nullptr;
    if (arr[t] == nullptr) {
      arr[t] = node;
    } else {
      LL *head = arr[t];
      while (head->next != nullptr) {
        head = head->next;
      }
      head->next = node;
    }

    bbt.insert(t);
  }

  int count = 0;
  while (!bbt.empty()) {
    auto it = bbt.begin();
    int h = *it;
    int i_max = -1;
    // cout << "ITS: " << count << " " << h << endl;
    while (h > 0) {
      LL *head = arr[h];
      if (head == nullptr) {
        break;
      }

      // cout << "H " << h << endl;
      if (head->pos > i_max) {
        // cout << "H ERase " << h << endl;

        i_max = head->pos;
        arr[h] = head->next;

        it = bbt.find(h);
        bbt.erase(it);
        h--;
      } else {
        while (head->next != nullptr && head->next->pos < i_max)
          head = head->next;
        if (head->next != nullptr) {
          // cout << "H ERase " << h << endl;

          LL *node = head->next;
          i_max = node->pos;
          head->next = node->next;
          it = bbt.find(h);
          bbt.erase(it);

          h--;
        } else {
          break;
        }
      }
    }
    count++;
  }
  cout << count << endl;

  return 0;
}
