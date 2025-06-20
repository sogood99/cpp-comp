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
  void nextPermutation(vector<int> &nums) {
    int i = nums.size() - 1, l = nums.size() - 1;

    while (i >= 0) {
      if (nums[i] < nums[l]) {
        break;
      }
      if (nums[i] > nums[l]) {
        l = i;
      }
      i--;
    }

    if (i < 0) {
      sort(nums.begin(), nums.end());
      return;
    }

    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] > nums[i] && nums[j] < nums[l]) {
        l = j;
      }
    }
    swap(nums[i], nums[l]);

    sort(nums.begin() + i + 1, nums.end());
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
