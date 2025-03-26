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

double myPow(double x, int n) {
  if (n < 0) {
    n = -n;
    x = 1 / x;
  }

  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return x;
  }

  double res = 1;
  if (n % 2 == 1) {
    res *= x;
  }

  double p = myPow(x, n / 2);
  res = res * p * p;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << myPow(2.0, -2) << endl;

  return 0;
}
