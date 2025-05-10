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
  bool check(vector<int> &nums, int k, int l) {
    int n = nums.size(), cnt = 0;

    for (int i = 0; i < n;) {
      if (nums[i] <= l) {
        cnt++;
        i += 2;
      } else {
        i++;
      }

      if (cnt >= k) {
        return true;
      }
    }

    return false;
  }

public:
  int minCapability(vector<int> &nums, int k) {
    int n = nums.size();

    int low = 1, high = 1e9, res = -1;
    while (low <= high) {
      int m = (low + high) / 2;

      if (check(nums, k, m)) {
        res = m;
        high = m - 1;
      } else {
        low = m + 1;
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
