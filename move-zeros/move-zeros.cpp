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
const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18;  // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
 public:
  void merge(vector<int>& nums, int i, int m, int j) {
    int k = i;

    while (k <= m) {
      if (nums[k] == 0) {
        break;
      }
      k++;
    }

    if (k > m) {
      return;
    }

    int sz = (m - k + 1);
    int z = m + 1;
    while (z <= j && nums[z] != 0) {
      if (nums[z] == 0) {
        break;
      }

      swap(nums[z - sz], nums[z]);
      z++;
    }
  }

  void moveZerosRec(vector<int>& nums, int i, int j) {
    if (i >= j) {
      return;
    }

    int m = (i + j) / 2;

    moveZerosRec(nums, i, m);
    moveZerosRec(nums, m + 1, j);
    merge(nums, i, m, j);
  }

  void moveZeroes(vector<int>& nums) {
    moveZerosRec(nums, 0, nums.size() - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  vector<int> nums = {0, 1, 0, 3, 12};

  s.moveZeroes(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}
