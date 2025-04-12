#include <algorithm>
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
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    vector<int> v;

    v.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
      auto it = lower_bound(v.begin(), v.end(), nums[i]);

      if (it == v.end()) {
        v.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }

    return v.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
