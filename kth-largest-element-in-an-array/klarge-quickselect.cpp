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
  int findKthLargest(vector<int> &nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (true) {
      int p = rand() % (r - l + 1) + l;
      int i = partition(nums, l, r, p);
      if (i == k - 1) {
        return nums[i];
      } else if (i > k - 1) {
        r = i - 1;
      } else {
        l = i + 1;
      }
    }
  }

  int partition(vector<int> &nums, int l, int r, int p) {
    int z = nums[p];
    swap(nums[p], nums[r]);
    int j = l;
    for (int i = l; i < r; i++) {
      if (nums[i] > z) {
        swap(nums[i], nums[j++]);
      }
    }
    swap(nums[j], nums[r]);
    return j;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
