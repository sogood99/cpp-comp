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
  vector<vector<int>> combine(int n, int k) {

    vector<vector<int>> q = {{}};

    vector<vector<int>> res;

    for (int d = 1; d <= n; d++) {
      vector<vector<int>> nq;
      for (vector<int> &v : q) {
        if (v.size() == k) {
          res.push_back(v);
          continue;
        }

        nq.push_back(v);

        v.push_back(d);
        nq.push_back(v);
      }
      swap(q, nq);
    }

    for (auto &v : q) {
      if (v.size() == k) {
        res.push_back(v);
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
