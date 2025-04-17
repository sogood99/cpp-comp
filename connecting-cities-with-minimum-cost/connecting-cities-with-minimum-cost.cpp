#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <queue>

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
  int getParent(int j, vector<int> &parent) {
    while (parent[j] != j)
      j = parent[j];
    return j;
  }

public:
  int minimumCost(int n, vector<vector<int>> &connections) {
    // union find
    vector<int> parent(n + 1), sz(n + 1);
    for (int i = 1; i < n + 1; i++) {
      parent[i] = i;
      sz[i] = 1;
    }

    auto cmp = [&](const vector<int> &a, const vector<int> &b) {
      if (a[2] != b[2]) {
        return a[2] > b[2];
      }
      return a[0] > b[0];
    };

    std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(
        connections.begin(), connections.end(), cmp);

    int cost = 0;
    while (!pq.empty()) {
      auto &e = pq.top();
      pq.pop();
      int x = e[0], y = e[1], c = e[2];

      int px = getParent(x, parent), py = getParent(y, parent);

      if (px != py) {
        if (sz[px] < sz[py]) {
          swap(px, py);
          swap(x, y);
        }
        parent[py] = px;
        sz[px] += sz[py];
        cost += c;

        if (sz[px] == n) {
          return cost;
        }
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
