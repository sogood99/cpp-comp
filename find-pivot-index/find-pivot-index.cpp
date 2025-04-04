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
const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18;  // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n), suff(n);
    for (int i = 0; i < n; i++) {
      if (i != 0) {
        pre[i] = pre[i - 1] + nums[i - 1];
      } else {
        pre[0] = 0;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1) {
        suff[i] = 0;
      } else {
        suff[i] = suff[i + 1] + nums[i + 1];
      }
    }

    for (int i = 0; i < n; i++) {
      if (pre[i] == suff[i]) {
        return i;
      }
    }

    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
