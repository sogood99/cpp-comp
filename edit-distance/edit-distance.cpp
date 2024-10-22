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

#include <algorithm>
// Shortcuts for "common" constants
const int INF = 1e9; // 10^9 = 1B is < 2^31-1
// const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
private:
  string s1, s2;
  int n, m;

  int memo[510][510];

public:
  int minDistance(string word1, string word2) {

    fill_n(&memo[0][0], 510 * 510, INF);
    s1 = word1;
    s2 = word2;
    n = word1.size();
    m = word2.size();

    if (n == 0) {
      return m;
    } else if (m == 0) {
      return n;
    }

    for (int j = 0; j < 510; j++) {
      memo[j][m] = n - j;
      memo[n][j] = m - j;
    }
    memo[n][m] = 0;

    return dp(0, 0);
  }

  int dp(int i, int j) {
    int &memval = memo[i][j];
    if (memval < INF)
      return memval;

    if (s1[i] == s2[j]) {
      memval = min(memval, dp(i + 1, j + 1));
    }

    memval = min(memval, dp(i + 1, j) + 1);
    memval = min(memval, dp(i, j + 1) + 1);
    memval = min(memval, dp(i + 1, j + 1) + 1);

    return memval;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s, t;
  cin >> s >> t;
  cout << Solution().minDistance(s, t) << endl;

  return 0;
}
