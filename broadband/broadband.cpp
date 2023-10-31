#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <iomanip>

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

int m, n, k;
double s;
double memo[2010][110];
double pos[2010];

double best_ij[2010][2010];

double dp(int j, int c) {
  if (j == m + n) {
    return 0;
  }
  if (c == 0) {
    return INF;
  }

  double memval = memo[j][c];
  if (memval != -1) {
    return memval;
  }
  memval = INF;
  for (int i = j + 1; i <= m + n; i++) {

    double cv = best_ij[j][i];
    memval = min(memval, cv + dp(i, c - 1));
  }
  memo[j][c] = memval;
  return memval;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> n >> k >> s;

  fill_n(&memo[0][0], 2010 * 110, -1);

  for (int i = 0; i < m + n; i++) {
    cin >> pos[i];
  }
  sort(pos, pos + m + n);

  memset(best_ij, 0, 2010 * 2010);

  for (int j = 0; j < m + n; j++) {
    double mean_ij = 0;
    for (int i = j + 1; i <= m + n; i++) {
      mean_ij = mean_ij * (i - j - 1) / (i - j) + pos[i - 1] / (i - j);

      best_ij[j][i] = 0;
      for (int k = j; k < i; k++) {
        best_ij[j][i] += (mean_ij - pos[k]) * (mean_ij - pos[k]);
      }
    }
  }

  cout << setprecision(20) << dp(0, k) + (m + n) * (s / 2) * (s / 2) << endl;

  return 0;
}
