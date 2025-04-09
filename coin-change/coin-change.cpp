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
  vector<vector<int>> memo;

  int dp(int j, int a, vector<int> &coins) {
    if (a < 0) {
      return -1;
    }
    if (memo[j][a] != -2) {
      return memo[j][a];
    }
    int &val = memo[j][a];
    if (j == 0) {
      val = a == 0 ? 0 : -1;
    } else {
      val = -1;
      int cnt = dp(j, a - coins[j - 1], coins);
      if (cnt != -1) {
        val = cnt + 1;
      }
      int no_add = dp(j - 1, a, coins);
      if (no_add != -1) {
        val = val == -1 ? no_add : min(no_add, val);
      }
    }

    return val;
  }

public:
  int coinChange(vector<int> &coins, int amount) {
    memo = vector<vector<int>>(coins.size() + 1, vector<int>(amount + 1, -2));
    return dp(coins.size(), amount, coins);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
