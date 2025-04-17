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
  int countComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);

    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int cc = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        cc++;
        visited[i] = true;

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
          int u = q.front();
          q.pop();

          for (int v : adj[u]) {
            if (!visited[v]) {
              visited[v] = true;
              q.push(v);
            }
          }
        }
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
