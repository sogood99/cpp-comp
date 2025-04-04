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
  int longestSubarray(vector<int>& nums) {
    int k = 1, n = nums.size(), i = 0, j = 0;
    while (j < n) {
      if (nums[j] == 0) {
        k--;
      }
      if (k < 0) {
        if (nums[i] == 0) {
          k++;
        }
        i++;
      }
      j++;
    }
    return j - i - 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
