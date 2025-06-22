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
  long long kSum(vector<int> &nums, int k) {
    int n = nums.size();

    long long res = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) {
        res += i;
      } else {
        nums[i] = -nums[i];
      }
    }

    sort(nums.begin(), nums.end());

    priority_queue<pair<long long, int>> pq;

    pq.push({res - nums[0], 0});

    int i = 1;

    while (i < k) {
      i++;

      auto [s, j] = pq.top();
      pq.pop();
      pq.push({s - nums[j + 1], j + 1});
      pq.push({s + nums[j] - nums[j - 1], j + 1});
      res = s;
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
