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
  int maxSubArrayLen(vector<int> &nums, int k) {
    unordered_map<long long, pair<int, int>> m;
    m[0] = {-1, -1};

    long long ps = 0;
    int longest = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
      ps += nums[i];
      if (m.count(ps) == 0) {
        m[ps] = {i, i};
      } else {
        m[ps] = {m[ps].first, i};
      }
      long long d = ps - k;
      if (m.count(d) != 0) {
        auto [mn, mx] = m[d];
        longest = max(longest, i - mn);
      }
    }
    return longest;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
