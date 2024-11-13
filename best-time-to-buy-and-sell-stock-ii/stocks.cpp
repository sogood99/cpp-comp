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

int maxProfit(vector<int> &prices) {
  int length = -1, start_price = 0, last_price = 0, profit = 0;
  prices.push_back(-1);

  for (int p : prices) {
    if (length == -1) {
      length = 0;
      start_price = last_price = p;
    } else {
      if (last_price > p) {
        profit += (last_price - start_price) * (length > 0 ? 1 : 0);
        start_price = last_price = p;
        length = 0;
      } else {
        length++;
        last_price = p;
      }
    }
  }

  return profit;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> prices = {7, 1, 5, 3, 6, 4};

  cout << maxProfit(prices) << endl;

  return 0;
}
