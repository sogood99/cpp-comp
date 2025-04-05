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

class Solution {
public:
  vector<vector<int>> backtrack(int k, int n, int m) {
    if (k == 0 || n < 0 || m < 1) {
      return {};
    }

    vector<vector<int>> res;
    // use m
    if (k == 1 && n == m) {
      res.push_back({m});
    } else {
      auto v = backtrack(k - 1, n - m, m - 1);
      for (auto u : v) {
        u.push_back(m);
        res.push_back(u);
      }
    }

    // dont use m
    auto v = backtrack(k, n, m - 1);
    for (auto u : v) {
      res.push_back(u);
    }
    return res;
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    return backtrack(k, n, 9);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
