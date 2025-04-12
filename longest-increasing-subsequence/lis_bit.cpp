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

class BIT {
private:
  vi ft;

public:
  BIT(int m) { ft.assign(m + 1, 0); }

  int rsq(int i) {
    int s = 0;
    while (i > 0) {
      s = max(s, ft[i]);
      i -= (i) & (-i);
    }
    return s;
  }

  int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

  void update(int i, int val) {
    while (i < ft.size()) {
      ft[i] = max(ft[i], val);
    }
  }
};

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }

    set<int> sorted(nums.begin(), nums.end());

    unordered_map<int, int> rank;

    {
      int r = 1;

      for (int x : sorted) {
        rank[x] = r++;
      }
    }

    BIT b(n);

    int m = 1;

    for (int n : nums) {
      int r = rank[n];

      int v = b.rsq(r - 1);
      b.update(r, v + 1);
      m = max(m, v + 1);
    }
    return m;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
