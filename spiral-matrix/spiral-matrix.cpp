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
  void spiral_traveral(vector<vector<int>> &matrix, int i, int j, int m, int n,
                       vector<int> &spiral_mat) {
    if (m <= 0 || n <= 0) {
      return;
    }

    if (m == 1) {
      // go single line
      for (int k = 0; k < n; k++) {
        spiral_mat.push_back(matrix[i][j + k]);
      }
    } else if (n == 1) {
      for (int k = 0; k < m; k++) {
        spiral_mat.push_back(matrix[i + k][j]);
      }
    } else {
      // loop
      for (int k = 0; k < n; k++) {
        spiral_mat.push_back(matrix[i][j + k]);
      }
      for (int k = 1; k < m; k++) {
        spiral_mat.push_back(matrix[i + k][j + n - 1]);
      }
      for (int k = 1; k < n; k++) {
        spiral_mat.push_back(matrix[i + m - 1][j - k + n - 1]);
      }
      for (int k = 1; k < m - 1; k++) {
        spiral_mat.push_back(matrix[i - k + m - 1][j]);
      }
      spiral_traveral(matrix, i + 1, j + 1, m - 2, n - 2, spiral_mat);
    }
  }

public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> spiral_mat;
    spiral_mat.reserve(m * n);
    spiral_traveral(matrix, 0, 0, m, n, spiral_mat);

    return spiral_mat;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
