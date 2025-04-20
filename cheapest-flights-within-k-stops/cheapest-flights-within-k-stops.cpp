#include <algorithm>
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <cstdint>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    k++;

    vector<vector<pair<int, int>>> adj(n);
    for (vector<int> &e : flights) {
      int u = e[0], v = e[1], c = e[2];
      adj[u].emplace_back(v, c);
    }

    vector<int> dist(n, INT_MAX);
    vector<int> time(n, INT_MAX);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    pq.push({0, {0, src}});

    while (!pq.empty()) {
      auto [d, p] = pq.top();
      auto [t, u] = p;
      pq.pop();

      if (dist[u] > d) {
        dist[u] = d;
      } else if (time[u] > t) {
        time[u] = t;
      } else {
        continue;
      }

      if (t + 1 <= k) {
        for (auto [v, c] : adj[u]) {
          if (d + c < dist[v] || t + 1 < time[v])
            pq.push({d + c, {t + 1, v}});
        }
      }
    }

    return dist[dst] < INT_MAX ? dist[dst] : -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
