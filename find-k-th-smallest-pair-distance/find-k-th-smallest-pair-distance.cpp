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
  int smallestDistancePair(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> diff;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (int i = 0; i < n - 1; i++) {
      diff.push_back(nums[i + 1] - nums[i]);
      pq.push({diff.back(), i});
    }

    while (--k) {
      auto [d, j] = pq.top();
      pq.pop();
      cout << d << endl;

      if (j + 1 < diff.size()) {
        pq.push({d + diff[j + 1], j + 1});
      }
    }

    return pq.top().first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  vector<int> v = {9, 10, 7, 10, 6, 1, 5, 4, 9, 8};

  s.smallestDistancePair(v, 18);

  return 0;
}
