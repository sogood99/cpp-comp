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
  vector<vector<int>> memo = vector<vector<int>>(2, vector<int>(50000, -1));

  int dp(int i, int b, vector<int> &price, int fee) {
    int n = price.size();
    if (memo[b][i] != -1) {
      return memo[b][i];
    }

    if (i == n - 1) {
      if (b) {
        memo[b][i] = 0;
      } else {
        memo[b][i] = price[i] - fee;
      }
      return memo[b][i];
    }

    int &val = memo[b][i];
    val = dp(i + 1, b, price, fee);
    if (b) {
      val = max(val, dp(i + 1, 1 - b, price, fee) - price[i]);
    } else {
      val = max(val, dp(i + 1, 1 - b, price, fee) + price[i] - fee);
    }
    return val;
  }

  int maxProfit(vector<int> &prices, int fee) { return dp(0, 1, prices, fee); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
