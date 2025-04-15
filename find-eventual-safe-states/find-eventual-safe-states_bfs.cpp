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
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();

    vector<vector<int>> adj_T(n);
    vector<int> indegree(n, 0);

    for (int u = 0; u < n; u++) {
      for (int v : graph[u]) {
        adj_T[v].push_back(u);
        indegree[u]++;
      }
    }

    vector<bool> safe_term(n, false);
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        q.push(i);
        safe_term[i] = true;
      }
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : adj_T[u]) {
        if (--indegree[v] == 0) {
          q.push(v);
          safe_term[v] = true;
        }
      }
    }

    vector<int> res;

    for (int i = 0; i < n; i++) {
      if (safe_term[i]) {
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
