#include <algorithm>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll x[810], y[810];

  int T;
  cin >> T;
  for (int j = 1; j <= T; j++) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> y[i];
    }

    sort(x, x + n);
    sort(y, y + n, greater<int>());

    ll s = 0;
    for (int i = 0; i < n; i++) {
      s += x[i] * y[i];
    }

    cout << "Case #" << j << ": " << s << endl;
  }

  return 0;
}
