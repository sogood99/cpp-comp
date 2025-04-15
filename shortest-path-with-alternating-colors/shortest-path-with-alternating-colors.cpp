#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <vector>

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
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                       vector<vector<int>> &blueEdges) {

    vector<vector<int>> adj_r(n), adj_b(n);

    for (vector<int> &e : redEdges) {
      int a = e[0], b = e[1];
      adj_r[a].push_back(b);
    }

    for (vector<int> &e : blueEdges) {
      int u = e[0], v = e[1];
      adj_b[u].push_back(v);
    }

    // 1 => last edge red, 2 => last edge blue, 0 dont care
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    vector<int> visited_b(n, -1), visited_r(n, -1);
    visited_b[0] = 0, visited_r[0] = 0;

    while (!q.empty()) {
      auto [u, c] = q.front();
      q.pop();

      if (c != 1) {
        // go through all red edges
        for (int v : adj_r[u]) {
          if (visited_r[v] == -1) {
            visited_r[v] = visited_b[u] + 1;
            q.emplace(v, 1);
          }
        }
      }

      if (c != 2) {
        // go through all blue edges
        for (int v : adj_b[u]) {
          if (visited_b[v] == -1) {
            visited_b[v] = visited_r[u] + 1;
            q.emplace(v, 2);
          }
        }
      }
    }

    auto cmp = [](int a, int b) {
      if (a == -1)
        return b;
      if (b == -1)
        return a;
      return min(a, b);
    };

    vector<int> res(n);

    for (int i = 0; i < n; i++) {
      res[i] = cmp(visited_r[i], visited_b[i]);
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
