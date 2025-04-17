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
  int trap(vector<int> &height) {
    int n = height.size(), total_area = 0;

    vector<int> ms;
    for (int i = 0; i < n; i++) {
      while (!ms.empty() && height[ms.back()] <= height[i]) {
        int hm = height[ms.back()];
        ms.pop_back();
        if (ms.empty())
          break;
        int hl = height[ms.back()], l = ms.back();

        total_area += min(height[i] - hm, hl - hm) * (i - l - 1);
      }
      ms.emplace_back(i);
    }

    return total_area;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
