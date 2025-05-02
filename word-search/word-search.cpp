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
  bool inBoard(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
  }

private:
  bool dfs(int i, int j, vector<vector<char>> &board,
           vector<vector<bool>> &visited, string word, int k) {
    if (visited[i][j]) {
      return false;
    }
    if (k == word.size() - 1) {
      return true;
    }
    int m = board.size(), n = board[0].size();

    visited[i][j] = true;

    if (inBoard(i + 1, j, m, n) && word[k + 1] == board[i + 1][j]) {
      if (dfs(i + 1, j, board, visited, word, k + 1)) {
        return true;
      }
    }

    if (inBoard(i - 1, j, m, n) && word[k + 1] == board[i - 1][j]) {
      if (dfs(i - 1, j, board, visited, word, k + 1)) {
        return true;
      }
    }

    if (inBoard(i, j + 1, m, n) && word[k + 1] == board[i][j + 1]) {
      if (dfs(i, j + 1, board, visited, word, k + 1)) {
        return true;
      }
    }

    if (inBoard(i, j - 1, m, n) && word[k + 1] == board[i][j - 1]) {
      if (dfs(i, j - 1, board, visited, word, k + 1)) {
        return true;
      }
    }

    visited[i][j] = false;

    return false;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == word[0]) {
          if (dfs(i, j, board, visited, word, 0)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
