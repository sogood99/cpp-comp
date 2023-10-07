#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {

  vector<int> memo = vector<int>(64, -1);

public:
  int integerBreak(int n, bool isSplit = false) {
    if (n == 1) {
      return 1;
    }
    if (memo[n] != -1) {
      return memo[n];
    }

    int m = 0;
    for (int i = 1; i < n; i++) {
      m = max(m, integerBreak(n - i, true) * i);
    }
    if (isSplit)
      m = max(m, n);

    memo[n] = m;

    return m;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << Solution().integerBreak(6) << endl;

  return 0;
}
