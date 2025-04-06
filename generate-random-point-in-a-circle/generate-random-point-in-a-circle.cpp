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

class Solution {
public:
  double r, x_c, y_c;

  double gen() { return (rand() / (double)RAND_MAX) * 2 * r - r; }

  Solution(double radius, double x_center, double y_center) {
    r = radius;
    x_c = x_center;
    y_c = y_center;
  }

  double inCircle(double x, double y) { return x * x + y * y <= r * r; }

  vector<double> randPoint() {
    double x = gen(), y = gen();
    while (!inCircle(x, y)) {
      x = gen(), y = gen();
    }

    return {x + x_c, y + y_c};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
