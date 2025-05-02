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
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    set<int> s(nums.begin(), nums.end());
    map<int, int> freq;
    set<vector<int>> cnt;

    for (int n : nums) {
      freq[n]++;
    }

    for (auto it = s.begin(); it != s.end(); it++) {
      int a = *it;
      for (auto jt = it; jt != s.end(); jt++) {
        int b = *jt;
        int c = -a - b;

        if (c < b)
          break;

        freq[a]--;
        freq[b]--;

        if (freq[b] >= 0 && freq[c] > 0) {
          vector<int> v = {a, b, c};
          sort(v.begin(), v.end());
          if (cnt.count(v) == 0) {
            res.push_back(v);
            cnt.insert(v);
          }
        }

        freq[a]++;
        freq[b]++;
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
