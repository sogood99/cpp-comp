#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <vector>

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
  void backtrack(vector<int> &current, vector<int> &candidates, int remain,
                 int strt, vector<vector<int>> &res) {
    if (remain == 0) {
      res.push_back(current);
      return;
    }
    if (remain < 0) {
      return;
    }

    for (int i = strt; i < candidates.size(); i++) {
      if (candidates[i] > remain)
        continue;

      current.push_back(candidates[i]);
      backtrack(current, candidates, remain - candidates[i], i, res);

      current.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> current;

    backtrack(current, candidates, target, 0, res);

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
