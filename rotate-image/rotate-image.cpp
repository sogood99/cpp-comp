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
  void rotate(vector<vector<int>> &matrix, int x, int sz) {
    for (int j = x + 1; j < x + sz; j++) {
      int i = x;
      swap(matrix[i][j], matrix[2 * x + sz - 1 - j][i]);
    }

    for (int i = x + 1; i < x + sz; i++) {
      int j = x + sz - 1;
      swap(matrix[i][j], matrix[j][2 * x + sz - 1 - i]);
    }

    for (int i = x + 1; i < x + sz; i++) {
      int j = x + sz - 1;
      swap(matrix[i][j], matrix[2 * x + sz - 1 - i][x]);
    }
  }

  void print(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }

public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size(), i = 0, sz = n;

    while (i < n / 2 && sz > 1) {
      rotate(matrix, i, sz);
      i++;
      sz -= 2;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
