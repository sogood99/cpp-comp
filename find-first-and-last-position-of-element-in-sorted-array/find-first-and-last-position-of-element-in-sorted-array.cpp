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
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();

    int l = 0, r = n - 1, i1 = -1, i2 = -1;

    while (l <= r) {
      int m = (r + l) / 2;
      if (nums[m] == target) {
        i1 = m;
      }

      if (nums[m] >= target) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    l = 0, r = n - 1;

    while (l <= r) {
      int m = (r + l) / 2;
      if (nums[m] == target) {
        i2 = m;
      }

      if (nums[m] > target) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    return {i1, i2};
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
