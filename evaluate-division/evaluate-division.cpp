#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <utility>

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
  double dfs(string &start, string &end,
             map<string, vector<pair<string, double>>> &adj) {
    if (adj.count(start) == 0) {
      return -1.;
    }

    vector<pair<string, double>> stk = {{start, 1.0}};
    set<string> visited;
    visited.insert(start);

    while (!stk.empty()) {
      auto [u, val] = stk.back();
      stk.pop_back();
      if (u == end) {
        return val;
      }

      for (auto [v, mv] : adj[u]) {
        if (visited.count(v) == 0) {
          visited.insert(v);
          double nv = val * mv;

          stk.push_back({v, nv});
        }
      }
    }
    return -1.;
  }

  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {

    map<string, vector<pair<string, double>>> adj;

    for (int i = 0; i < equations.size(); i++) {
      vector<string> &p = equations[i];
      string &u = p[0], v = p[1];
      double val = values[i];

      if (adj.count(u) == 0) {
        adj[u] = vector<pair<string, double>>();
      }
      if (adj.count(v) == 0) {
        adj[v] = vector<pair<string, double>>();
      }

      adj[u].push_back({v, val});
      adj[v].push_back({u, 1 / val});
    }

    vector<double> res;
    for (vector<string> &p : queries) {
      string &u = p[0], v = p[1];
      double val = dfs(u, v, adj);
      res.push_back(val);
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
