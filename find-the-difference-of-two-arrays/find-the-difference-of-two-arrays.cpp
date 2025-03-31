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
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    set<int> s1, s2;

    for (int n1 : nums1) {
      s1.insert(n1);
    }
    for (int n2 : nums2) {
      s2.insert(n2);
    }

    vector<vector<int>> res(2);

    for (int n1 : s1) {
      if (!s2.contains(n1)) {
        res[0].push_back(n1);
      }
    }

    for (int n2 : s2) {
      if (!s1.contains(n2)) {
        res[1].push_back(n2);
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
