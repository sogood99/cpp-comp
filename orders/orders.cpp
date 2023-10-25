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

ll memo[110 * 30010];
int c[110];

ll *getmemo(int i, int j) { return (memo + i * 110 + j); }

ll dp(int cv, int j) {
  if (j < 0 && cv == 0) {
    return 1;
  }
  if (cv < 0 || j < 0) {
    return 0;
  }

  ll *memval = getmemo(cv, j);

  if (*memval != -1)
    return *memval;

  if (c[j] == 0) {
    *memval = 2 * dp(cv, j - 1);
  } else {
    *memval = dp(cv, j - 1) + dp(cv - c[j], j);
  }
  return *memval;
}

void print_dp(int cv, int j) {
  vi v;
  while (cv > 0 && j >= 0) {
    if (dp(cv - c[j], j) == 1) {
      v.push_back(j);
      cv -= c[j];
    } else {
      j -= 1;
    }
  }

  for (int i = v.size() - 1; i > 0; i--) {
    cout << v[i] + 1 << " ";
  }
  cout << v[0] + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int s;

  fill_n(memo, 110 * 30010, -1);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> s;
    ll rv = dp(s, n - 1);
    if (rv == 1) {
      print_dp(s, n - 1);
    } else if (rv > 1) {
      cout << "Ambiguous" << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }

  return 0;
}
