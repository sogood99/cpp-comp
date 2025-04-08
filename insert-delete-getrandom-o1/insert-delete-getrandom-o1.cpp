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

class RandomizedSet {
  map<int, int> mp; // value -> idx in array
  vector<int> vals;

public:
  RandomizedSet() {}

  bool insert(int val) {
    // vals[n] = val;
    if (mp.count(val)) {
      return false;
    }
    vals.push_back(val);
    mp[val] = vals.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (!mp.count(val)) {
      return false;
    }
    size_t n = vals.size();

    mp[vals[n - 1]] = mp[val];
    swap(vals[n - 1], vals[mp[val]]);
    vals.pop_back();
    mp.erase(val);
    return true;
  }

  int getRandom() {
    size_t n = vals.size();
    int i = rand() % n;
    return vals[i];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
