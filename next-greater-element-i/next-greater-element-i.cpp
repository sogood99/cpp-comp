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
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<int> res(m, -1);

    unordered_map<int, int> idx;

    for (int i = 0; i < m; i++) {
      idx[nums1[i]] = i;
    }

    vector<int> ms;

    for (int i = 0; i < n; i++) {
      while (!ms.empty() && nums2[ms.back()] < nums2[i]) {
        int t = nums2[ms.back()];
        if (idx.count(t)) {
          res[idx[t]] = nums2[i];
        }
        ms.pop_back();
      }
      ms.push_back(i);
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
