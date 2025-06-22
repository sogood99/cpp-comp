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
  int getMaxLen(vector<int> &nums) {
    int n = nums.size();
    vector<int> last(2, -1);
    // last index where last[0] = index where num of
    // negative is even, last[1] = index where odd

    int mx = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] < 0) {
        swap(last[0], last[1]);
      } else if (nums[i] == 0) {
        last[0] = last[1] = -1;
      }

      if (last[0] == -1 && nums[i] > 0) {
        last[0] = i;
      } else if (last[1] == -1 && nums[i] < 0) {
        last[1] = i;
      }

      if (last[0] != -1) {
        mx = max(mx, i - last[0] + 1);
      }
    }

    return mx;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
