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

int jump(vector<int> &nums) {
  size_t n = nums.size();
  int last_m = 0, current_m = 0, nj = 0;

  for (int i = 0; i < n; i++) {
    if (last_m >= n - 1) {
      return nj;
    }
    current_m = max(current_m, nums[i] + i);
    if (i == last_m) {
      last_m = current_m;
      nj++;
    }
  }

  return nj;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> nums = {2, 3, 1, 1, 4};

  cout << jump(nums) << endl;

  return 0;
}