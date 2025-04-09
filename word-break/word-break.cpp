#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <unordered_set>

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
  vector<int> memo;

  int dp(int j, string &s, unordered_set<string> &wordDict) {
    if (memo[j] != -1) {
      return memo[j];
    }
    if (j == 0) {
      memo[0] = 1;
      return 1;
    }
    int &val = memo[j];

    for (int i = j - 1; i >= 0; i--) {
      int sz = j - i;
      string sub = s.substr(i, sz);
      if (wordDict.count(sub)) {
        val = dp(i, s, wordDict);
      }
      if (val == 1) {
        return 1;
      }
    }
    return 0;
  }

public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    memo = vector<int>(n + 1, -1);
    unordered_set<string> wordSet;
    for (string &d : wordDict) {
      wordSet.insert(d);
    }
    return dp(n, s, wordSet);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
