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
  int minCostII(vector<vector<int>> &costs) {
    int k = costs[0].size();
    vector<int> dp = vector<int>(k);
    int n = costs.size();
    for (int c = 0; c < k; c++) {
      dp[c] = costs[0][c];
    }

    for (int i = 1; i < n; i++) {
      vector<int> ndp = vector<int>(k, INT_MAX);
      for (int c = 0; c < k; c++) {
        for (int co = 0; co < k; co++) {
          if (co == c)
            continue;

          ndp[c] = min(ndp[c], dp[co] + costs[i][c]);
        }
      }
      swap(ndp, dp);
    }

    int mn = INT_MAX;
    for (int c = 0; c < k; c++) {
      mn = min(mn, dp[c]);
    }

    return mn;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
