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
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    int l = 0, r = m * n - 1;

    while (l <= r) {
      int md = (l + r) / 2;

      int i = md / n, j = md % n;

      if (matrix[i][j] == target) {
        return true;
      } else if (matrix[i][j] < target) {
        l = md + 1;
      } else {
        r = md - 1;
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
