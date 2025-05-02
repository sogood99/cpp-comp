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
  int search(vector<int> &nums, int target) {
    // first binary search
    // nums[i] - nums[k] == [0, +, ++, ... - - - -]
    int n = nums.size();
    int l = 0, r = n - 1, res = -1;
    while (l <= r) {
      int m = (r - l) / 2 + l;
      if (nums[m] - nums[0] >= 0) {
        res = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    // nums'[0] .. nums'[res]  nums'[res+1] .. nums'[n-1]
    // nums[k+1] .. nums[n-1]  nums[0] ...     nums[k]
    // res == n - 1 - k - 1 => k == n - res - 2

    int k = n - res - 2;

    l = 0, r = n - 1;

    while (l <= r) {
      int m = (r - l) / 2 + l;
      int mi = m <= k ? m + res + 1 : m - k - 1;
      if (nums[mi] == target) {
        return mi;
      } else if (nums[mi] < target) {
        l = m + 1;
      } else {
        r = m - 1;
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
