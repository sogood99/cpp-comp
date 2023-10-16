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

const ll M = 1000010;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int X[M], Y[M];

  fill_n(X, M, 0);
  fill_n(Y, M, 0);
  int i, j;

  int n;
  cin >> n;
  for (int k = 1; k <= n; k++) {
    cin >> i >> j;
    X[k] = i;
    Y[k] = j;
  }

  ll moves = 0;
  sort(X + 1, X + n + 1);
  sort(Y + 1, Y + n + 1);

  for (int i = 1; i <= n; i++) {
    moves += abs(X[i] - i);
    moves += abs(Y[i] - i);
  }

  // for (int i = 1; i <= n; i++) {
  //   ll k = 1;
  //   while (X[i] > 1 && !(i - k < 1 && i + k > n)) {
  //     if (i - k >= 1 && X[i - k] == 0) {
  //       X[i]--, X[i - k]++;
  //       moves += k;
  //     }
  //     if (i + k <= n && X[i] > 1 && X[i + k] == 0) {
  //       X[i]--, X[i + k]++;
  //       moves += k;
  //     }
  //   }
  // }
  //
  // for (int j = 1; j <= n; j++) {
  //   ll k = 1;
  //   while (Y[j] > 1 && !(j - k < 1 && j + k > n)) {
  //     if (j - k >= 1 && Y[j - k] == 0) {
  //       Y[j]--, Y[j - k]++;
  //       moves += k;
  //     }
  //     if (j + k <= n && Y[j] > 1 && Y[j + k] == 0) {
  //       Y[j]--, Y[j + k]++;
  //       moves += k;
  //     }
  //   }
  // }

  cout << moves << endl;

  return 0;
}
