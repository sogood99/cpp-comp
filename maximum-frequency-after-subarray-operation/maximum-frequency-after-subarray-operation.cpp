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
  int maxFrequency(vector<int> &nums, int k) {
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == k)
        cnt++;
    }

    // find subarray [i..j] such that d = freq[e] - freq[k] is maximized
    // return cnt + d

    int d = 0;
    unordered_map<int, int> freq;

    for (int v = 1; v <= 50; v++) {
      if (v == k)
        continue;
      int cd = 0;
      for (int i = 0; i < nums.size(); i++) {
        int dx = 0;
        if (nums[i] == v) {
          dx = 1;
        } else if (nums[i] == k) {
          dx = -1;
        }

        cd = max(cd + dx, dx);
        d = max(cd, d);
      }
    }

    return cnt + d;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
