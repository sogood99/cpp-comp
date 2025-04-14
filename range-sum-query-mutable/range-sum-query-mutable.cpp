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

class NumArray {
  size_t n;
  vi st;

  int l(int p) { return 2 * p; }
  int r(int p) { return 2 * p + 1; }

  void build(int p, int L, int R, vi &nums) {
    if (L == R) {
      st[p] = nums[L];
    } else {
      int m = (L + R) / 2;
      build(l(p), L, m, nums);
      build(r(p), m + 1, R, nums);
      st[p] = st[l(p)] + st[r(p)];
    }
  }

  void update(int p, int L, int R, int i, int val) {
    if (L == R) {
      st[p] = val;
    } else {
      int m = (L + R) / 2;
      if (i <= m) {
        update(l(p), L, m, i, val);
      } else {
        update(r(p), m + 1, R, i, val);
      }
      st[p] = st[l(p)] + st[r(p)];
    }
  }

  int query(int p, int L, int R, int i, int j) {
    if (i > R || j < L)
      return 0;
    if (i <= L && R <= j) {
      return st[p];
    }
    int m = (L + R) / 2;
    return query(l(p), L, m, i, j) + query(r(p), m + 1, R, i, j);
  }

public:
  NumArray(vector<int> &nums) {
    n = 1;
    while (n <= nums.size()) {
      n *= 2;
    }
    nums.resize(n);

    st.assign(4 * n, 0);
    build(1, 0, n - 1, nums);
  }

  void update(int index, int val) { update(1, 0, n - 1, index, val); }

  int sumRange(int left, int right) { return query(1, 0, n - 1, left, right); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vi A = {-1};
  NumArray na(A);
  cout << na.sumRange(0, 0) << endl;

  return 0;
}
