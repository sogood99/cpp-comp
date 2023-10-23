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

bool solve() {

  int n;
  cin >> n;
  if (n == 0) {
    return false;
  }

  vi v(n, 0), p(n, -1), dp(n, 1);

  int tm = 0, tmv = 0;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int j = i - 1; j >= 0; j--) {
      if (v[i] > v[j]) {
        if (dp[i] < dp[j] + 1) {
          p[i] = j;
          dp[i] = dp[j] + 1;
        } else if (dp[i] == dp[j] + 1 && v[p[i]] > v[j]) {
          p[i] = j;
        }
      }
    }
    if (tm < dp[i]) {
      tm = dp[i];
      tmv = i;
    } else if (tm == dp[i] && v[tmv] > v[i]) {
      tmv = i;
    }
  }

  cout << tm << ' ';
  vi r(tm);
  for (int i = tm - 1; i >= 0; i--) {
    r[i] = v[tmv];
    tmv = p[tmv];
  }
  for (int i = 0; i < tm - 1; i++) {
    cout << r[i] << ' ';
  }
  cout << r[tm - 1] << endl;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (solve())
    ;

  return 0;
}
