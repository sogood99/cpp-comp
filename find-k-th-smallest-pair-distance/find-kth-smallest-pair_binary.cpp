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
  int smallestDistancePair(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int l = 0, r = nums[n - 1] - nums[0], res = -1;

    while (l <= r) {
      int m = (l + r) / 2;

      // count number of pairs w/ dist <= m, if # of pairs is greater, set res =
      // m, and r = m-1;

      int i = 0, j = 0, cnt = 0;
      while (i < n && j < n) {
        while (j < n && nums[j] - nums[i] <= m) {
          j++;
        }
        // i+1 ~ j - 1 inclusive, j-1 - (i+1) +1
        cnt += j - i - 1;
      }

      if (cnt >= k) {
        res = m;
        r = m - 1;
      } else {
        l = m + 1;
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
