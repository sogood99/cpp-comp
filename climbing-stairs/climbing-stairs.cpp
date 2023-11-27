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

int memo[50] = {-1};

int dp(int n) {
  if (n < 0) {
    return 0;
  }
  int &memval = memo[n];
  if (memval != -1) {
    return memval;
  }

  memval = dp(n - 1) + dp(n - 2);
  return memval;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fill_n(memo, 50, -1);
  memo[0] = 1;

  cout << dp(3) << endl;

  return 0;
}
