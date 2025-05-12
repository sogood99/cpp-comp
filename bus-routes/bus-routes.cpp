#include <bits/extc++.h>
#include <bits/stdc++.h>

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
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {
    unordered_map<int, vector<int>> route_i;
    unordered_set<int> visited;
    unordered_set<int> visited_route;

    for (int r = 0; r < routes.size(); r++) {
      for (auto i : routes[r]) {
        route_i[i].push_back(r);
      }
    }

    queue<pair<int, int>> q;
    q.push({source, 0});

    visited.insert(source);

    while (!q.empty()) {
      auto [u, d] = q.front();
      q.pop();

      if (u == target) {
        return d;
      }

      for (auto r : route_i[u]) {
        if (visited_route.count(r))
          continue;
        for (auto v : routes[r]) {
          if (visited.count(v) == 0) {
            visited.insert(v);
            q.push({v, d + 1});
          }
        }
        visited_route.insert(r);
      }
    }

    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
