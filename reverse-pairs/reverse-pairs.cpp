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

  int mergeSort(vector<int> &nums, int i, int j) {
    if (i >= j) {
      return 0;
    }
    int m = (i + j) / 2;
    int lc = mergeSort(nums, i, m);
    int rc = mergeSort(nums, m + 1, j);

    int a = i, cnt = 0;
    for (int b = m + 1; b <= j; b++) {
      while (a <= m && nums[a] <= 2ll * nums[b]) {
        a++;
      }
      cnt += max(m - a + 1, 0);
    }

    int l = i, r = m + 1, k = 0;
    vector<int> tmp(j - i + 1);
    while (l <= m && r <= j) {
      if (nums[l] <= nums[r]) {
        tmp[k++] = nums[l++];
      } else {
        tmp[k++] = nums[r++];
      }
    }
    while (l <= m) {
      tmp[k++] = nums[l++];
    }
    while (r <= j) {
      tmp[k++] = nums[r++];
    }
    for (int k = 0; k < j - i + 1; k++) {
      nums[i + k] = tmp[k];
    }
    return cnt + lc + rc;
  }

public:
  int reversePairs(vector<int> &nums) {
    return mergeSort(nums, 0, nums.size() - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
