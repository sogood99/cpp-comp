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

int C, n;
int v[2010], w[2010];
int memo[2010 * 2010];

int *get_memo(int j, int rw) { return (memo + 2010 * j + rw); }

int dp(int j, int rw) {
  if (rw < 0) {
    return -INF;
  } else if (rw == 0) {
    return 0;
  }
  if (j <= 0) {
    return 0;
  }
  int *memval = get_memo(j, rw);
  if (*memval >= 0) {
    return *memval;
  }

  int ad = dp(j - 1, rw - w[j - 1]) + v[j - 1];
  int nad = dp(j - 1, rw);
  // cout << j << " " << rw << " " << ad << " " << nad << endl;

  if (ad >= nad) {
    *memval = ad;
    return ad;
  }
  *memval = nad;
  return nad;
}

void print_dp(int n, int C) {
  vi idx;
  while (n > 0) {
    if (dp(n - 1, C - w[n - 1]) + v[n - 1] == dp(n, C)) {
      idx.push_back(n - 1);
      C -= w[n - 1];
    }
    n--;
  }
  cout << idx.size() << endl;
  for (int i = idx.size() - 1; i > 0; i--) {
    cout << idx[i] << " ";
  }
  if (idx.size() > 0) {
    cout << idx[0] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> C >> n) {
    fill_n(memo, 2010 * 2010, -1);

    for (int i = 0; i < n; i++) {
      cin >> v[i] >> w[i];
    }

    dp(n, C);

    print_dp(n, C);
  }

  return 0;
}
