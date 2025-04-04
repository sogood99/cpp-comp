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
  bool isBorder(ii u, vector<vector<char>> &maze) {
    int n = maze.size(), m = maze[0].size();

    return u.first == 0 || u.first == n - 1 || u.second == 0 ||
           u.second == m - 1;
  }

  bool inGrid(ii u, vector<vector<char>> &maze) {
    int n = maze.size(), m = maze[0].size();
    return u.first >= 0 && u.first <= n - 1 && u.second >= 0 &&
           u.second <= m - 1;
  }

  ii addCoord(ii u, ii d) { return {u.first + d.first, u.second + d.second}; }

  char getVal(ii u, vector<vector<char>> &maze) {
    return maze[u.first][u.second];
  }

  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    queue<pair<ii, int>> q;
    set<ii> visited;
    ii ep = {entrance[0], entrance[1]};
    q.push({ep, 0});
    visited.insert(ep);

    vector<ii> diff = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
      auto [u, dst] = q.front();
      q.pop();

      cout << u.first << " " << u.second << " " << getVal(u, maze) << endl;

      if (isBorder(u, maze) && u != ep) {
        return dst;
      }

      for (ii d : diff) {
        ii v = addCoord(u, d);
        if (inGrid(v, maze) && !visited.count(v) && getVal(v, maze) == '.') {
          visited.insert(v);
          q.push({v, dst + 1});
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
