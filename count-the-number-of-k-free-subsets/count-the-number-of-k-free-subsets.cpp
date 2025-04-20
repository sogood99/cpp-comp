#include <algorithm>
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <unordered_set>

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
  long long countTheNumOfKFreeSubsets(vector<int> &nums, int k) {
    vector<vector<int>> v(k);
    for (int i : nums) {
      v[i % k].push_back(i);
    }

    long long cnt = 1;

    for (int b = 0; b < k; b++) {
      sort(v[b].begin(), v[b].end());

      int sz = v[b].size();

      if (sz == 0) {
        continue;
      }

      long long pre1 = 1, pre2 = 0;

      long long num_subsets = 1;

      for (int i = 1; i < sz; i++) {
        long long curr = 1;
        if (v[b][i] != v[b][i - 1] + k) {
          curr += pre1;
        } else {
          curr += pre2;
        }

        pre2 = pre1;
        pre1 += curr;

        num_subsets += curr;
      }

      cnt *= (num_subsets + 1);
    }

    return cnt;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  vector<int> nums = {2, 3, 5, 8};
  cout << s.countTheNumOfKFreeSubsets(nums, 5);

  return 0;
}
