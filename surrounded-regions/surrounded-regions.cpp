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
private:
  int m, n;

  const vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  bool atEdge(vector<vector<char>> &board, vector<vector<bool>> &visited, int i,
              int j) {
    if (visited[i][j] || board[i][j] != 'O')
      return false;

    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
      return true;

    visited[i][j] = true;
    bool e = false;
    for (auto &dt : d) {
      auto [dx, dy] = dt;
      e = e || atEdge(board, visited, i + dx, j + dy);
    }

    return e;
  }

  void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int i,
           int j, const bool e) {
    if (i < 0 || i >= m || j < 0 || j >= n)
      return;

    if (visited[i][j] || board[i][j] != 'O')
      return;

    visited[i][j] = true;
    if (e) {
      board[i][j] = 'O';
    } else {
      board[i][j] = 'X';
    }

    for (auto &dt : d) {
      auto [dx, dy] = dt;
      dfs(board, visited, i + dx, j + dy, e);
    }
  }

public:
  void solve(vector<vector<char>> &board) {
    m = board.size(), n = board[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));
    vector<vector<bool>> visitedAE(m, vector<bool>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        bool e = atEdge(board, visitedAE, i, j);
        dfs(board, visited, i, j, e);
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
