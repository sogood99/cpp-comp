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
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<int> stk = {0};
    vector<bool> vst(n, false);
    vst[0] = true;
    int cnt = 0;

    vector<vector<int>> adj(n), rev(n);

    for (auto c : connections) {
      int u = c[0], v = c[1];
      adj[u].push_back(v);
      rev[v].push_back(u);
    }

    while (!stk.empty()) {
      int u = stk.back();
      stk.pop_back();

      for (int v : adj[u]) {
        if (!vst[v]) {
          vst[v] = true;
          stk.push_back(v);
          cnt++;
        }
      }

      for (int v : rev[u]) {
        if (!vst[v]) {
          vst[v] = true;
          stk.push_back(v);
        }
      }
    }
    return cnt;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
