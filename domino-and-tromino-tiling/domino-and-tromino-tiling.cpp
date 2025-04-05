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

const int MOD = 1e9 + 7;

class Solution {
public:
  vector<vector<int>> memo = vector<vector<int>>(1010, vector<int>(3, -1));

  int dp(int n, int state) {
    if (n < 0) {
      return 0;
    }
    if (memo[n][state] >= 0) {
      return memo[n][state];
    }
    if (n == 0) {
      if (state == 0) {
        memo[0][0] = 1;
      } else {
        memo[0][state] = 0;
      }
      return memo[0][state];
    }

    int val = 0;
    if (state == 0) {
      val = dp(n - 2, 0);
      val = (val + dp(n - 1, 1)) % MOD;
      val = (val + dp(n - 1, 2)) % MOD;
      val = (val + dp(n - 1, 0)) % MOD;
    } else if (state == 1) {
      val = dp(n - 2, 0);
      val = (val + dp(n - 1, 2)) % MOD;
    } else {
      val = dp(n - 2, 0);
      val = (val + dp(n - 1, 1)) % MOD;
    }

    memo[n][state] = val;
    return val;
  }

  int numTilings(int n) {
    // 0 => both open
    // 1 => top open
    // 2 => bottom open
    return dp(n, 0);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
