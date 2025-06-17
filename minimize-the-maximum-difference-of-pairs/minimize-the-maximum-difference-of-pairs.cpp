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
  int minimizeMax(vector<int> &nums, int p) {
    if (p == 0) {
      return 0;
    }

    int n = nums.size();

    vector<pair<int, pair<int, int>>> v;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int val = abs(nums[i] - nums[j]);
        v.push_back({val, {i, j}});
      }
    }

    sort(v.begin(), v.end());

    int l = 0, r = 1e9, res = 0;

    while (l <= r) {
      int m = (l + r) / 2;
      vector<bool> contains(n);

      int cnt = 0, k = 0;
      while (cnt < p && k < v.size()) {
        auto [cv, pr] = v[k++];
        auto [l, r] = pr;

        if (contains[l] || contains[r]) {
          continue;
        }

        if (cv > m || cnt >= p) {
          break;
        }

        cnt++;
        contains[l] = true;
        contains[r] = true;
      }

      if (cnt >= p) {
        r = m - 1;
        res = m;
      } else {
        l = m + 1;
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
