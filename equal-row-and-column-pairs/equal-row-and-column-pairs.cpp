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
const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18;  // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
 public:
  bool checkGrid(int r, int c, vector<vector<int>>& grid) {
    // int n = grid.size();

    // for (int i = 0; i < n; i++){
    //     if (grid[r][i] != grid[i][c]){
    //         return false;
    //     }
    // }
    return true;
  }

  int equalPairs(vector<vector<int>>& grid) {
    map<int, vector<int>> h1, h2;

    int n = grid.size();

    for (int i = 0; i < n; i++) {
      // hash row i
      int h = 0;

      for (int j = 0; j < n; j++) {
        h = (7 * h + 11 * grid[i][j]) % 1234567;
      }

      if (h1.count(h) == 0) {
        vector<int> v;
        v.push_back(i);
        h1[h] = v;
      } else {
        h1[h].push_back(i);
      }
    }

    for (int j = 0; j < n; j++) {
      // hash row i
      int h = 0;

      for (int i = 0; i < n; i++) {
        h = (7 * h + 11 * grid[i][j]) % 1234567;
      }

      if (h2.count(h) == 0) {
        vector<int> v;
        v.push_back(j);
        h2[h] = v;
      } else {
        h2[h].push_back(j);
      }
    }

    auto i1 = h1.begin(), i2 = h2.begin();

    int cnt = 0;

    while (i1 != h1.end() && i2 != h2.end()) {
      int i = i1->first, j = i2->first;
      if (i == j) {
        for (int r : i1->second) {
          for (int c : i2->second) {
            if (checkGrid(r, c, grid)) {
              cnt++;
            }
          }
        }
        i1++;
        i2++;
      } else if (i < j) {
        i1++;
      } else {
        i2++;
      }
    }

    return cnt;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
