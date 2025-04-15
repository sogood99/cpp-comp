#include <algorithm>
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <queue>

#define LSOne(S) ((S) & -(S))

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class LFUCache {
private:
  unordered_map<int, list<ii>> linked_map;        // maps freq to linked list
  unordered_map<int, int> freq;                   // maps key to freq
  unordered_map<int, list<ii>::iterator> itermap; // maps key to list iter
  int capacity, size = 0, min_freq = 1;

public:
  LFUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    // f = freq[key], linked_map[freq] splice to linked_map[freq+1].begin(),
    // freq[key]++;
    if (freq.count(key) == 0) {
      return -1;
    }

    int f = freq[key];
    linked_map[f + 1].splice(linked_map[f + 1].begin(), linked_map[f],
                             itermap[key]);
    freq[key]++;
    if (f == min_freq && linked_map[f].begin() == linked_map[f].end()) {
      min_freq++;
    }
    return itermap[key]->second;
  }

  void put(int key, int value) {
    if (freq.count(key) != 0) {
      // update value, freq, linked_map
      itermap[key]->second = value;
      int f = freq[key];
      linked_map[f + 1].splice(linked_map[f + 1].begin(), linked_map[f],
                               itermap[key]);
      freq[key]++;
      if (f == min_freq && linked_map[f].begin() == linked_map[f].end()) {
        min_freq++;
      }
    } else {
      // new value, size < cap or size == cap
      if (size < capacity) {
        size++;
      } else {
        // size == capacity
        auto [old_key, old_value] = linked_map[min_freq].back();
        linked_map[min_freq].pop_back();
        freq.erase(old_key);
        itermap.erase(old_key);
      }
      linked_map[1].emplace_front(key, value);
      auto it = linked_map[1].begin();
      itermap[key] = it;
      freq[key] = 1;
      min_freq = 1;
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
