#include <algorithm>
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
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    int n = startTime.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    map<int, int> memo;

    sort(idx.begin(), idx.end(), [&endTime](const int a, const int b) {
      return endTime[a] < endTime[b];
    });

    int j = 0;

    int best_profit = 0;
    memo[0] = 0;

    for (int j = 0; j < n; j++) {
      int i = idx[j];
      auto it = prev(memo.upper_bound(startTime[i]));

      memo[endTime[i]] = max(best_profit, profit[i] + it->second);

      best_profit = max(best_profit, memo[endTime[i]]);
    }

    return best_profit;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> st = {1, 2, 3, 4, 6}, et = {3, 5, 10, 6, 9},
              pf = {20, 20, 100, 70, 60};

  Solution s;

  cout << s.jobScheduling(st, et, pf) << endl;

  return 0;
}
