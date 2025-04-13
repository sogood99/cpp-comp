#include <algorithm>
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
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

bool cmp(const vector<int> &l, const vector<int> &r) {
  if (l[0] != r[0]) {
    return l[0] < r[0];
  }
  return l[1] < r[1];
}

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    int n = intervals.size();

    if (n == 0) {
      return {};
    }

    int s = intervals[0][0], e = intervals[0][1];
    vector<vector<int>> res;

    for (int i = 1; i < n; i++) {
      int curr_s = intervals[i][0], curr_e = intervals[i][1];

      if (e >= curr_s) {
        e = max(curr_e, e);
      } else {
        res.push_back({s, e});
        s = curr_s;
        e = curr_e;
      }
    }

    res.push_back({s, e});

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
