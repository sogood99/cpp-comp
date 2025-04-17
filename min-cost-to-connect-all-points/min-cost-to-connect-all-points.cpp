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
  int manDist(const vector<int> &a, const vector<int> &b) {
    return abs(b[0] - a[0]) + abs(b[1] - a[1]);
  }

public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[0] = 0;

    std::priority_queue<pair<int, int>, vector<pair<int, int>>,
                        greater<pair<int, int>>>
        pq;
    pq.emplace(0, 0);

    int total_dist = 0;

    while (!pq.empty()) {
      auto [c, u] = pq.top();
      pq.pop();
      if (visited[u]) {
        continue;
      }
      visited[u] = true;
      dist[u] = c;
      total_dist += dist[u];

      for (int v = 0; v < n; v++) {
        int d;
        if (!visited[v] && (d = manDist(points[u], points[v])) < dist[v]) {
          dist[v] = d;
          pq.emplace(d, v);
        }
      }
    }
    return total_dist;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
