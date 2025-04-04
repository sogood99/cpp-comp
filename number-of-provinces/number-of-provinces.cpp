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
const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18;  // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
 public:
  void dfs(int u, vector<vector<int>>& isConnected, vector<bool>& seen) {
    vector<int> stk = {u};
    int n = isConnected.size();

    while (!stk.empty()) {
      int v = stk.back();
      stk.pop_back();

      for (int i = 0; i < n; i++) {
        if (isConnected[v][i] && !seen[i]) {
          stk.push_back(i);
          seen[i] = true;
        }
      }
    }
  }

  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();

    vector<bool> seen(n, false);
    int cc = 0;

    for (int u = 0; u < n; u++) {
      if (!seen[u]) {
        cc++;
        seen[u] = true;
        dfs(u, isConnected, seen);
      }
    }
    return cc;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
