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
  vector<int> memo = vector<int>(1010, -1);
  int dp(int i, vector<int> &cost) {
    if (memo[i] >= 0) {
      return memo[i];
    }
    if (i <= 1) {
      memo[i] = cost[i];
      return memo[i];
    }

    memo[i] = min(dp(i - 1, cost), dp(i - 2, cost)) + cost[i];
    return memo[i];
  }

  int minCostClimbingStairs(vector<int> &cost) {
    cost.push_back(0);
    return dp(cost.size() - 1, cost);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
