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
  long long numberOfWays(string s) {
    int n = s.size();

    vector<vector<long long>> dp(3, vector<long long>(2));

    for (int i = 0; i < n; i++) {
      int c = s[i] - '0';
      for (int l = 0; l < 3; l++) {
        dp[l][c] += l == 0 ? 1 : dp[l - 1][1 - c];
      }
    }

    return dp[2][0] + dp[2][1];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
