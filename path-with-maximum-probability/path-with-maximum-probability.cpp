#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <iterator>

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
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start_node,
                        int end_node) {

    vector<vector<pair<int, double>>> adj(n);

    int E = edges.size();
    for (int i = 0; i < E; i++) {
      int u = edges[i][0], v = edges[i][1];
      double p = succProb[i];

      adj[u].emplace_back(v, p);
      adj[v].emplace_back(u, p);
    }

    std::priority_queue<pair<double, int>> pq;
    vector<double> best_prob(n, 0);
    best_prob[start_node] = 1;
    pq.emplace(1, start_node);

    while (!pq.empty()) {
      auto [p, u] = pq.top();
      pq.pop();

      if (u == end_node) {
        return p;
      }

      for (auto [v, p_e] : adj[u]) {
        double np = p * p_e;
        if (best_prob[v] < np) {
          best_prob[v] = np;
          pq.emplace(np, v);
        }
      }
    }

    return best_prob[end_node];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
