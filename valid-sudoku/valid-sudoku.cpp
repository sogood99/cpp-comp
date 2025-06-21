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
  bool checkRow(int i, vector<vector<char>> &board) {
    vector<int> freq(9);

    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        int v = board[i][j] - '1';
        freq[v]++;
        if (freq[v] > 1)
          return false;
      }
    }

    return true;
  }

  bool checkCol(int j, vector<vector<char>> &board) {
    vector<int> freq(9);

    for (int i = 0; i < 9; i++) {
      if (board[i][j] != '.') {
        int v = board[i][j] - '1';
        freq[v]++;
        if (freq[v] > 1)
          return false;
      }
    }

    return true;
  }

  bool checkBox(int i, int j, vector<vector<char>> &board) {
    vector<int> freq(9);

    for (int di = 0; di < 3; di++) {
      for (int dj = 0; dj < 3; dj++) {
        int x = i * 3 + di, y = j * 3 + dj;
        if (board[x][y] != '.') {
          int v = board[x][y] - '1';
          freq[v]++;
          if (freq[v] > 1)
            return false;
        }
      }
    }

    return true;
  }

public:
  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      if (!checkRow(i, board))
        return false;
      if (!checkCol(i, board))
        return false;
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (!checkBox(i, j, board))
          return false;
      }
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
