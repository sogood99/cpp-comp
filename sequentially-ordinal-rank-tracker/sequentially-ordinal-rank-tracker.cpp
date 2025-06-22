#include <bits/extc++.h>
#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class SORTracker {
  map<int, set<string>, greater<int>> mp;
  map<int, set<string>>::iterator mp_it = mp.end();
  set<string>::iterator st_it;

public:
  SORTracker() {}

  void add(string name, int score) {
    mp[score].insert(name);
    if (mp_it == mp.end()) {
      mp_it = prev(mp.end());
      st_it = prev(mp_it->second.end());
    } else {
      if (score < mp_it->first) {
        return;
      } else if (score == mp_it->first) {
        if (*st_it > name) {
          st_it = prev(st_it);
        }
      } else {
        if (st_it == mp_it->second.begin()) {
          // move map iterator to before, and set iterator to the last of
          // set<int>
          mp_it = prev(mp_it);
          st_it = prev(mp_it->second.end());
        } else {
          st_it = prev(st_it);
        }
      }
    }
  }

  string get() {
    string ret = *st_it;
    st_it = next(st_it);

    if (st_it == mp_it->second.end()) {
      mp_it = next(mp_it);
      if (mp_it != mp.end()) {
        st_it = mp_it->second.begin();
      }
    }

    return ret;
  }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
