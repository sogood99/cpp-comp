#include <bits/extc++.h>
#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    int n = arr.size();
    int res = 0;
    const int c = 1e9 + 7;

    vector<int> eo(n + 1), o(n + 1), e(n + 1);
    e[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
      eo[i] = (arr[i] + eo[i + 1]) % 2;
      if (eo[i] == 0) {
        e[i] = e[i + 1] + 1;
        o[i] = o[i + 1];
      } else {
        e[i] = e[i + 1];
        o[i] = o[i + 1] + 1;
      }
    }

    for (int i = 0; i < n; i++) {
      if (eo[i] == 0) {
        // arr[i] + arr[i+1] .. arr[n-1] is even
        res = (res + o[i]) % c;
      } else {
        res = (res + e[i]) % c;
      }
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
