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
private:
  long long backtrack(unordered_set<int> &hm, vector<int> &nums, int j, int k) {
    if (j < 0) {
      // check if possible
      for (int a : hm) {
        if (hm.count(a + k) || hm.count(a - k)) {
          return 0;
        }
      }
      return 1;
    }
    // dont insert nums[i]
    int cnt = 0;
    cnt += backtrack(hm, nums, j - 1, k);
    hm.insert(nums[j]);
    cnt += backtrack(hm, nums, j - 1, k);
    hm.erase(nums[j]);
    return cnt;
  }

public:
  long long countTheNumOfKFreeSubsets(vector<int> &nums, int k) {
    unordered_set<int> hm;
    return backtrack(hm, nums, nums.size() - 1, k);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
