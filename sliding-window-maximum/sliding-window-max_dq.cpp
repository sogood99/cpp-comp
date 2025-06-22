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
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();

    vector<int> res(n - k + 1);

    deque<int> dq;

    for (int i = 0; i < k - 1; i++) {
      while (!dq.empty()) {
        int j = dq.back();

        if (nums[j] <= nums[i]) {
          dq.pop_back();
        } else {
          break;
        }
      }

      dq.push_back(i);
    }

    for (int i = 0; i < n - k + 1; i++) {
      if (dq.front() < i) {
        dq.pop_front();
      }

      while (!dq.empty()) {
        int j = dq.back();

        if (nums[j] <= nums[i + k - 1]) {
          dq.pop_back();
        } else {
          break;
        }
      }
      dq.push_back(i + k - 1);

      res.push_back(nums[dq.front()]);
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
