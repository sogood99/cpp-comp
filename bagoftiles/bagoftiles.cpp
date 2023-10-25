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

ll choose(ll n, ll k) {
  if (k == 0)
    return 1;
  return (n * choose(n - 1, k - 1)) / k;
}

int n, m, t;
ll A[32];

// m * n * t
ll memo[32][32][10010];

ll dp(int m, int n, int t) {
  // cout << m << " " << n << " " << t << " " << A[m] << endl;
  if (n == 0 && t == 0)
    return 1;

  if (m < 0 || n < 0 || t < 0)
    return 0;

  ll &memval = memo[m][n][t];

  if (memval != -1)
    return memval;

  memval = dp(m - 1, n - 1, t - A[m]) + dp(m - 1, n, t);
  return memval;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int g;
  cin >> g;
  int k = 0;
  while (k++ < g) {
    fill_n(&memo[0][0][0], 32 * 32 * 10010, -1);

    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> A[i];
    }

    cin >> n >> t;

    ll rv = dp(m - 1, n, t);

    cout << "Game " << k << " -- " << rv << " : " << choose(m, n) - rv << endl;
  }

  return 0;
}
