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
  vector<vector<int>> memo;
  int dp(int i, int j, string &s1, string &s2, string &s3) {
    if (memo[i][j] != -1) {
      return memo[i][j];
    }

    int &val = memo[i][j];

    if (i == 0 || j == 0) {
      if (i == 0 && j == 0) {
        val = 1;
      } else if (i == 0) {
        val = s3[j - 1] == s2[j - 1] ? dp(i, j - 1, s1, s2, s3) : 0;
      } else if (j == 0) {
        val = s3[i - 1] == s1[i - 1] ? dp(i - 1, j, s1, s2, s3) : 0;
      }
      return val;
    }

    if (s3[i + j - 1] == s1[i - 1] && dp(i - 1, j, s1, s2, s3)) {
      val = 1;
    } else if (s3[i + j - 1] == s2[j - 1] && dp(i, j - 1, s1, s2, s3)) {
      val = 1;
    } else {
      val = 0;
    }

    return val;
  }

public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size();
    if (n + m != s3.size()) {
      return false;
    }
    memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
    {
      bool isprefix = true;
      for (int i = 1; i <= m; i++) {
        if (s1[i - 1] != s3[i - 1]) {
          isprefix = false;
        }
        memo[i][0] = isprefix ? 1 : 0;
      }
      isprefix = true;
      for (int i = 1; i <= n; i++) {
        if (s2[i - 1] != s3[i - 1]) {
          isprefix = false;
        }
        memo[0][i] = isprefix ? 1 : 0;
      }
    }
    int val = dp(m, n, s1, s2, s3);
    return val;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
