#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>

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

const int iter = 164249;

inline long double f(long double a, long double s, long double d) {
  return a + s - a * cosh(d / 2 / a);
}

long double finda(long double s, long double d) {
  long double l = 0, r = 5000000., m;

  for (int i = 0; i < iter; i++) {
    m = (l + r) / 2;
    // cout << f(m, s, d) << " " << m << endl;
    if (f(m, s, d) < 0) {
      l = m;
    } else {
      r = m;
    }
  }
  return m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long double d, s, a;
  cin >> d >> s;

  a = finda(s, d);

  cout << setprecision(20) << 2 * a * sinh(d / 2 / a) << endl;

  return 0;
}
