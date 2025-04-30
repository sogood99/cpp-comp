#include <algorithm>
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
  long long countSubarrays(vector<int> &nums, int k) {
    long long cnt = 0;
    int n = nums.size();

    int max_el = *max_element(nums.begin(), nums.end());

    int i = 0, v = 0;
    for (int j = 0; j < n; j++) {
      v += nums[j] == max_el ? 1 : 0;

      while (i < j) {
        if (v == k && nums[i] == max_el)
          break;
        if (v < k)
          break;
        v -= nums[i++] == max_el ? 1 : 0;
      }
      // [0..i : j] are all doable
      if (v >= k)
        cnt += i + 1;
    }

    return cnt;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
