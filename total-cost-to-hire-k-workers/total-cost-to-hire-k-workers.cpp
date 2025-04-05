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

class Solution {
public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    int n = costs.size(), i = candidates, j = n - candidates - 1;

    std::priority_queue<ii, vector<ii>, greater<ii>> pq;
    if (i <= j) {
      // insert from [0..i-1] [j+1..n-1]
      for (int k = 0; k < i; k++) {
        pq.push({costs[k], k});
      }
      for (int k = j + 1; k < n; k++) {
        pq.push({costs[k], k});
      }
    } else {
      // insert all
      for (int k = 0; k < n; k++) {
        pq.push({costs[k], k});
      }
    }

    ll tc = 0, m = 0;
    while (m < k && !pq.empty()) {
      auto [c, l] = pq.top();
      pq.pop();
      tc += c;
      m++;

      if (i <= j) {
        // add one more candidate
        if (l < i) {
          // add in costs[i], i
          pq.push({costs[i], i++});
        } else {
          pq.push({costs[j], j--});
        }
      }
    }

    return tc;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
