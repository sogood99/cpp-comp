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
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;

    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
      while (!res.empty() && res[res.size() - 1][0] == nums[i] && i < n - 2)
        i++;
      int j = i + 1, k = n - 1;

      int s = nums[i] + nums[j] + nums[k];

      while (j < k) {
        if (s == 0) {
          vector<int> v = {nums[i], nums[j], nums[k]};
          if (res.empty() || res[res.size() - 1] != v) {
            res.push_back(v);
          }
        }
        if (s <= 0) {
          j++;
        } else {
          k--;
        }
        s = nums[i] + nums[j] + nums[k];
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
