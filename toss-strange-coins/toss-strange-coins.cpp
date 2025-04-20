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
  vector<vector<double>> memo; // memo[j][target]

  double dp(int j, int t, vector<double> &prob) {
    if (j < 0 || t < 0) {
      return 0;
    }
    if (j == 0) {
      if (t == 0) {
        return 1;
      } else {
        return 0;
      }
    }

    double &p = memo[j][t];
    if (p >= 0) {
      return p;
    }

    p = (1 - prob[j - 1]) * dp(j - 1, t, prob) +
        prob[j - 1] * dp(j - 1, t - 1, prob);
    return p;
  }

public:
  double probabilityOfHeads(vector<double> &prob, int target) {
    int n = prob.size();
    memo = vector<vector<double>>(n + 1, vector<double>(target + 1, -1));
    return dp(n, target, prob);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
