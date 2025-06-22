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
  void floodfill(int i, int j, vector<vector<bool>> &mp,
                 vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    static const vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    mp[i][j] = true;

    for (auto &p : d) {
      int x = i + p.first, y = j + p.second;
      if (x < 0 || x >= m || y < 0 || y >= n) {
        continue;
      }

      if (heights[x][y] < heights[i][j] || mp[x][y]) {
        continue;
      }
      mp[x][y] = true;

      floodfill(x, y, mp, heights);
    }
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();

    vector<vector<bool>> pac(m, vector<bool>(n)), atl(m, vector<bool>(n));

    for (int i = 0; i < m; i++) {
      floodfill(i, 0, pac, heights);
      floodfill(i, n - 1, atl, heights);
    }
    for (int j = 0; j < n; j++) {
      floodfill(0, j, pac, heights);
      floodfill(m - 1, j, atl, heights);
    }

    vector<vector<int>> res;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (pac[i][j] && atl[i][j]) {
          res.push_back({i, j});
        }
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
