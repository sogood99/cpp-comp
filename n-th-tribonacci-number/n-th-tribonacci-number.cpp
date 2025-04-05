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
  vector<int> memo = vector<int>(40, -1);

  int tribonacci(int n) {
    if (memo[n] != -1) {
      return memo[n];
    }
    if (n == 0) {
      memo[0] = 0;
      return 0;
    } else if (n == 1) {
      memo[1] = 1;
      return 1;
    } else if (n == 2) {
      memo[2] = 1;
      return 1;
    }

    memo[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    return memo[n];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
