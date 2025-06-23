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

class TicTacToe {
private:
  vector<vector<int>> board;
  int n = 0;

public:
  TicTacToe(int n) : n(n) { board = vector<vector<int>>(n, vector<int>(n, 0)); }

  int move(int row, int col, int player) {
    board[row][col] = player;

    // check vert
    bool vertWin = true;
    for (int i = 0; i < n; i++) {
      if (board[i][col] != player) {
        vertWin = false;
        break;
      }
    }
    if (vertWin)
      return player;
    // check hor
    bool horWin = true;
    for (int j = 0; j < n; j++) {
      if (board[row][j] != player) {
        horWin = false;
        break;
      }
    }
    if (horWin)
      return player;

    // check diag
    if (row == col) {
      bool diagWin = true;
      for (int i = 0; i < n; i++) {
        if (board[i][i] != player) {
          diagWin = false;
          break;
        }
      }
      if (diagWin)
        return player;
    }

    if (row == n - 1 - col) {
      bool diagWin = true;
      for (int i = 0; i < n; i++) {
        if (board[i][n - 1 - i] != player) {
          diagWin = false;
          break;
        }
      }
      if (diagWin)
        return player;
    }

    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
