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

  int n;
  double p, k;
  double t = 0, t_l;
  double t_tot = 0;
  cin >> n >> p >> k;
  for (int j = 0; j < n; j++) {
    t_l = t;
    cin >> t;
    t_tot += (t - t_l) * (1.0 + j * 0.01 * p);
  }

  t_tot += (k - t) * (1.0 + n * 0.01 * p);

  cout << std::setprecision(15) << t_tot << endl;

  return 0;
}
