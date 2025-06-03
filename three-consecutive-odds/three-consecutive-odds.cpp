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
  bool threeConsecutiveOdds(vector<int> &arr) {
    int n = arr.size();
    if (n < 3)
      return false;
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
      cnt += arr[i] % 2 == 1 ? 1 : 0;
    }

    if (cnt == 3)
      return true;

    for (int j = 3; j < n; j++) {
      cnt += arr[j] % 2 == 1 ? 1 : 0;
      cnt -= arr[j - 3] % 2 == 1 ? 1 : 0;

      if (cnt == 3)
        return true;
    }

    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
