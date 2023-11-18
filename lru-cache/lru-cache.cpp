#include <bits/extc++.h>
#include <bits/stdc++.h>

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

class LRUCache {
private:
  list<ii> linkedlist; // linked list of key values
  unordered_map<int, list<ii>::iterator> um;
  int capacity;

public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {

    if (um.count(key) == 0) {
      return -1;
    }

    linkedlist.splice(linkedlist.begin(), linkedlist, um[key]);

    return um[key]->second;
  }

  void put(int key, int value) {
    if (get(key) != -1) {
      um[key]->second = value;
    } else {
      if (linkedlist.size() >= capacity) {
        int pop_key = linkedlist.back().first;
        linkedlist.pop_back();
        um.erase(pop_key);
      }
      linkedlist.push_front({key, value});
      um[key] = linkedlist.begin();
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
