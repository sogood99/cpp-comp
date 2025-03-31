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
const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18;  // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> v;

    for (int i : asteroids) {
      if (i < 0) {
        while (true) {
          if (!(v.size() > 0 && v.back() > 0)) {
            v.push_back(i);
            break;
          }
          if (v.back() + i == 0) {
            v.pop_back();
            break;
          } else if (v.back() + i > 0) {
            break;
          } else {
            v.pop_back();
            continue;
          }
        }
      } else {
        v.push_back(i);
      }
    }
    return v;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
