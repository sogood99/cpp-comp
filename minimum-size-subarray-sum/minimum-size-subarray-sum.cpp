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
  int minSubArrayLen(int target, vector<int> &nums) {
    int s = 0, sz = INT_MAX, n = nums.size(), l = 0;
    for (int r = 0; r < n; r++) {
      s += nums[r];
      while (l <= r && s >= target) {
        sz = min(sz, r - l + 1);
        s -= nums[l];
        l++;
      }
    }

    return sz < INT_MAX ? sz : 0;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
