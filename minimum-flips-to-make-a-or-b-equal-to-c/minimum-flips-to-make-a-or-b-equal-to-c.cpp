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
  int minFlips(int a, int b, int c) {
    int x = (a | b) ^ c;
    int az = a & x; // flipped to 0
    int bz = b & x; // flipped to 0
    int fo = (az | bz) ^ x;

    int cnt = 0;

    while (az | bz | fo) {
      cnt += az % 2;
      cnt += bz % 2;
      cnt += fo % 2;
      az >>= 1;
      bz >>= 1;
      fo >>= 1;
    }
    return cnt;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
