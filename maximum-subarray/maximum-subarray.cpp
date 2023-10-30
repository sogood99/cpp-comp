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
  int maxSubArray(vector<int> &nums) {
    int s = 0, nums_size = nums.size(), ms = 0;
    for (int i = 0; i < nums_size; i++) {
      s += nums[i];
      s = max(s, 0);
      ms = max(s, ms);
    }

    if (ms == 0) {
      ms = nums[0];
      for (int i = 1; i < nums_size; i++) {
        ms = max(nums[i], ms);
      }
    }

    return ms;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
