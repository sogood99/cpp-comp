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
  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      if (manager[i] != -1)
        adj[manager[i]].push_back(i);
    }

    queue<pair<int, int>> q;
    q.emplace(headID, 0);

    int mt = 0;
    while (!q.empty()) {
      auto [u, t] = q.front();
      q.pop();

      if (adj[u].size() == 0) {
        mt = max(mt, t);
      } else {
        for (int v : adj[u]) {
          q.emplace(v, t + informTime[u]);
        }
      }
    }

    return mt;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
