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
  int minimumOperations(vector<int> &nums) {
    deque<long long> v(nums.begin(), nums.end());
    int ops = 0;

    while (v.size() > 1) {
      int vf = v.front(), vb = v.back();
      if (vf == vb) {
        v.pop_front();
        v.pop_back();
      } else if (vf < vb) {
        v.pop_front();
        v.front() += vf;
        ops++;
      } else {
        v.pop_back();
        v.back() += vb;
        ops++;
      }
    }

    return ops;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
