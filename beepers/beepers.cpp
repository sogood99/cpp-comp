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

int w, h, x, y;
ii A[15];

int memo[12][1050];

int get_mask(int n) {
  int rv = 0;
  for (int i = 0; i < n; i++) {
    rv += (1 << i);
  }
  return rv;
}

int md(ii l, ii r) { return abs(l.first - r.first) + abs(l.second - r.second); }

int dp(int j, int mask) {
  if (mask == 0)
    return md({x, y}, A[j]);

  int &memoval = memo[j][mask];
  if (memoval != -1)
    return memoval;

  int m = mask;
  memoval = INF;
  while (m) {
    int two_pow_v = LSOne(m);
    int v = __builtin_ctz(two_pow_v);
    // cout << v << endl;
    memoval = min(memoval, md(A[j], A[v]) + dp(v, mask ^ two_pow_v));
    m -= two_pow_v;
  }
  return memoval;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int g, n;
  cin >> g;
  for (int i = 0; i < g; i++) {
    cin >> w >> h;
    fill_n(&memo[0][0], 12 * 1050, -1);
    cin >> x >> y >> n;
    for (int j = 0; j < n; j++) {
      int t1, t2;
      cin >> t1 >> t2;
      A[j] = {t1, t2};
    }
    A[n] = {x, y};
    // cout << n << endl;
    cout << dp(n, get_mask(n)) << endl;
  }

  return 0;
}
