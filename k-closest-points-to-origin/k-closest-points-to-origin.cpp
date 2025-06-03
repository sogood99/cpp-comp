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
private:
  double dist(vector<int> &p) { return sqrt(p[0] * p[0] + p[1] * p[1]); }

public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<pair<double, int>> q;

    int n = points.size();
    for (int i = 0; i < n; i++) {
      vector<int> &p = points[i];
      double d = dist(p);

      q.push({d, i});
      if (q.size() > k) {
        q.pop();
      }
    }

    vector<vector<int>> res;
    while (!q.empty()) {
      auto [d, u] = q.top();
      res.push_back(points[u]);
      q.pop();
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
