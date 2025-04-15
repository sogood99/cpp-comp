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
private:
  // vector<int> visited, -1 => not visited, 0 visited, 1 safe, 2 terminal, 3
  // not safe/terminal

  int dfs(int n, vector<vector<int>> &graph, vector<int> &visited) {
    if (visited[n] == 0) {
      // cycles
      visited[n] = 3;
      return 3;
    }

    if (visited[n] != -1) {
      // not visited before
      return visited[n];
    }

    visited[n] = 0;

    if (graph[n].size() == 0) {
      visited[n] = 2;
      return 2;
    }

    for (int v : graph[n]) {
      int k = dfs(v, graph, visited);
      if (k == 3) {
        visited[n] = 3;
        return 3;
      }
    }
    visited[n] = 1;
    return 1;
  }

public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> visited(n, -1), res;

    for (int i = 0; i < n; i++) {
      if (visited[i] == -1) {
        dfs(i, graph, visited);
      }

      if (visited[i] != 3) {
        res.push_back(i);
      }
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
