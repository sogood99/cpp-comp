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
public:
  vector<vector<int>> memo = vector<vector<int>>(1010, vector<int>(1010, -1));

  int dp(int i, int j, string &s1, string &s2) {
    int m = s1.length(), n = s2.length();
    cout << i << " " << j << endl;

    if (i >= m || j >= n) {
      return 0;
    }

    if (memo[i][j] != -1) {
      return memo[i][j];
    }

    int &val = memo[i][j];
    val = max(dp(i + 1, j, s1, s2), dp(i, j + 1, s1, s2));
    if (s1[i] == s2[j]) {
      val = max(val, 1 + dp(i + 1, j + 1, s1, s2));
    }
    return val;
  }

  int longestCommonSubsequence(string text1, string text2) {
    return dp(0, 0, text1, text2);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  string a = "abcde", b = "ace";

  s.longestCommonSubsequence(a, b);

  return 0;
}
