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
  long long minSum(vector<int> &nums1, vector<int> &nums2) {
    long long s1 = 0, s2 = 0;
    int z1 = 0, z2 = 0;

    for (int n : nums1) {
      s1 += n;
      if (!n)
        z1++;
    }

    for (int n : nums2) {
      s2 += n;
      if (!n)
        z2++;
    }

    if (z1 == 0 && s2 + z2 > s1) {
      return -1;
    }
    if (z2 == 0 && s1 + z1 > s2) {
      return -1;
    }
    return max(s2 + z2, s1 + z1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
