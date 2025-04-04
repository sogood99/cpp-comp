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
class Solution {
public:
  ii addCoord(ii u, ii d) { return {u.first + d.first, u.second + d.second}; }

  bool inGrid(ii u, vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    return 0 <= u.first && u.first < n && 0 <= u.second && u.second < m;
  }

  int getVal(ii u, vector<vector<int>> &grid) {
    return grid[u.first][u.second];
  }

  int orangesRotting(vector<vector<int>> &grid) {
    vector<ii> diff = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int t = 0, n = grid.size(), m = grid[0].size();
    vector<ii> q;
    bool has_fruit = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push_back({i, j});
        }
        if (grid[i][j] > 0) {
          has_fruit = true;
        }
      }
    }
    if (q.empty()) {
      if (has_fruit) {
        return -1;
      } else {
        return 0;
      }
    }

    while (!q.empty()) {
      vector<ii> nq;
      t++;

      for (ii u : q) {
        for (ii d : diff) {
          ii v = addCoord(u, d);
          if (inGrid(v, grid) && getVal(v, grid) == 1) {
            grid[v.first][v.second] = 2;
            nq.push_back(v);
          }
        }
      }

      swap(q, nq);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          return -1;
        }
      }
    }
    return t - 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
