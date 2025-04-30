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
private:
  vector<vector<int>> memo;
  int dp(int amount, int j, vector<int> &coins) {
    if (j == 0) {
      if (amount == 0) {
        return 1;
      }
      return 0;
    }
    if (amount < 0) {
      return 0;
    }

    int &val = memo[amount][j];
    if (val != -1) {
      return val;
    }

    val = dp(amount - coins[j - 1], j, coins) + dp(amount, j - 1, coins);
    return val;
  }

public:
  int change(int amount, vector<int> &coins) {
    memo = vector<vector<int>>(amount + 1, vector<int>(coins.size() + 1, -1));

    return dp(amount, coins.size(), coins);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
