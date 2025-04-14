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
  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();

    vector<int> color(n, -1); // 0 , 1

    queue<int> q;

    for (int i = 0; i < n; i++) {
      if (color[i] == -1) {
        q.push(i);
        color[i] = 0;
        while (!q.empty()) {
          int u = q.front();
          q.pop();

          for (int v : graph[u]) {
            if (color[v] == -1) {
              q.push(v);
              color[v] = 1 - color[u];
            } else if (color[v] == color[u]) {
              return false;
            }
          }
        }
      }
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
