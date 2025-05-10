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
private:
  void quicksort(vector<int> &nums, int i, int j) {
    if (i >= j) {
      return;
    }

    int m = (i + j) / 2;
    int p = nums[m];
    swap(nums[m], nums[j]);

    int idx = j;
    for (int k = j - 1; k >= i; k--) {
      if (nums[k] >= p) {
        swap(nums[k], nums[--idx]);
      }
    }

    swap(nums[idx], nums[j]);

    quicksort(nums, i, idx - 1);
    quicksort(nums, idx + 1, j);
  }

public:
  void sortColors(vector<int> &nums) { quicksort(nums, 0, nums.size() - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> v = {2, 0, 2, 1, 1, 0};

  Solution s;

  s.sortColors(v);

  return 0;
}
