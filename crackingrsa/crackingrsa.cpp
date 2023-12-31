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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  ll n, d, e, p, q, m;
  while (T--) {
    cin >> n >> d;
    ll sq = sqrt(n);
    for (p = 2; p <= sq; p++) {
      if (n % p == 0) {
        q = n / p;
        break;
      }
    }
    m = (p - 1) * (q - 1);

    for (e = 2; e < m; e++) {
      if (e * d % m == 1) {
        cout << e << endl;
        break;
      }
    }
  }

  return 0;
}
