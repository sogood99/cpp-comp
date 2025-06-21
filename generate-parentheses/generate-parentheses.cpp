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
  vector<string> generateParenthesis(int n) {
    vector<pair<string, ii>> q;
    q.push_back({"", {0, 0}});

    for (int i = 0; i < 2 * n; i++) {
      vector<pair<string, ii>> nq;
      for (auto &v : q) {
        auto [s, p] = v;

        if (p.first < n) {
          nq.push_back({s + '(', {p.first + 1, p.second + 1}});
        }

        if (p.second > 0) {
          nq.push_back({s + ')', {p.first, p.second - 1}});
        }
      }

      swap(q, nq);
    }

    vector<string> res;
    for (auto &p : q) {
      res.push_back(p.first);
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
