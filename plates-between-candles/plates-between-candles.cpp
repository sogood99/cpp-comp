#include <algorithm>
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
  vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
    vector<int> candles;
    int n = s.size();

    for (int i = 0; i < n; i++) {
      if (s[i] == '|')
        candles.push_back(i);
    }

    vector<int> res;

    for (auto &q : queries) {
      int l = q[0], r = q[1];

      // find l <= candles[i] and candles[j] <= r

      auto lb = lower_bound(candles.begin(), candles.end(), l);
      auto ub = upper_bound(candles.begin(), candles.end(), r);
      // r < candles[j]
      if (ub == candles.begin() || ub == lb) {
        res.push_back(0);
        continue;
      }

      ub = prev(ub);
      // ub == 3, lb == 1 => 1
      // ub - lb == 1, that means i want to subtract only 1

      int c = *ub - *lb - (ub - lb);

      res.push_back(c);
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
