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

class Solution {
public:
  int kEmptySlots(vector<int> &bulbs, int k) {
    set<int> litup;

    for (int i = 0; i < bulbs.size(); i++) {
      int x = bulbs[i];
      auto it = litup.upper_bound(x);

      if (it != litup.end() && *it - x == k + 1) {
        return i + 1;
      }

      if (it != litup.begin() && x - *prev(it) == k + 1) {
        return i + 1;
      }

      litup.insert(x);
    }

    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
