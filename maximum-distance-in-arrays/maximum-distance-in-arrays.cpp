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

class Solution {
public:
  int maxDistance(vector<vector<int>> &arrays) {
    int m = arrays.size();
    std::priority_queue<pair<int, int>> large;
    std::priority_queue<pair<int, int>, vector<pair<int, int>>,
                        greater<pair<int, int>>>
        small;

    for (int i = 0; i < m; i++) {
      int k = arrays[i].size();
      large.emplace(arrays[i][k - 1], i);
      small.emplace(arrays[i][0], i);

      if (large.size() > 2) {
        large.pop();
        small.pop();
      }
    }

    auto s = small.top(), l = large.top();
    small.pop();
    large.pop();
    if (s.second != l.second) {
      return l.first - s.first;
    } else {
      return max(l.first - small.top().first, large.top().first - s.first);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
