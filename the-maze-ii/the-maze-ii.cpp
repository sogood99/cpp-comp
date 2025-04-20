#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <queue>

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
private:
  bool inside(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
  }

public:
  int shortestDistance(vector<vector<int>> &maze, vector<int> &start,
                       vector<int> &destination) {
    int m = maze.size(), n = maze[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({0, start[0], start[1]});
    dist[start[0]][start[1]] = 0;

    while (!pq.empty()) {
      auto u = pq.top();
      pq.pop();
      int d = u[0], x = u[1], y = u[2];

      if (d > dist[x][y])
        continue;

      dist[x][y] = d;

      if (x == destination[0] && y == destination[1]) {
        return d;
      }

      int x_c, y_c, c;
      x_c = x, y_c = y, c = 0;
      while (inside(x_c + 1, y_c, m, n) && maze[x_c + 1][y_c] == 0) {
        x_c++;
        c++;
      }
      if (d + c < dist[x_c][y_c]) {
        pq.push({d + c, x_c, y_c});
      }

      x_c = x, y_c = y, c = 0;
      while (inside(x_c - 1, y_c, m, n) && maze[x_c - 1][y_c] == 0) {
        x_c--;
        c++;
      }
      if (d + c < dist[x_c][y_c]) {
        pq.push({d + c, x_c, y_c});
      }

      x_c = x, y_c = y, c = 0;
      while (inside(x_c, y_c + 1, m, n) && maze[x_c][y_c + 1] == 0) {
        y_c++;
        c++;
      }
      if (d + c < dist[x_c][y_c]) {
        pq.push({d + c, x_c, y_c});
      }

      x_c = x, y_c = y, c = 0;
      while (inside(x_c, y_c - 1, m, n) && maze[x_c][y_c - 1] == 0) {
        y_c--;
        c++;
      }
      if (d + c < dist[x_c][y_c]) {
        pq.push({d + c, x_c, y_c});
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
