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
private:
  // pre[i] == # of idx < i s.t. nums[idx] < nums[i]
  // post[i] == # of idx > i s.t. nums[idx] < nums[i]
  void mergeSort(vector<int> &nums, vector<int> &idx, int i, int j,
                 vector<int> &pre, vector<int> &post) {
    if (i >= j) {
      return;
    }

    int m = (i + j) / 2;
    mergeSort(nums, idx, i, m, pre, post);
    mergeSort(nums, idx, m + 1, j, pre, post);

    int a = i, b = m + 1;
    for (; b <= j; b++) {
      while (a <= m && nums[idx[a]] < nums[idx[b]]) {
        a++;
      }
      pre[idx[b]] += a - i;
    }
    a = i, b = m + 1;
    for (; a <= m; a++) {
      while (b <= j && nums[idx[b]] < nums[idx[a]]) {
        b++;
      }
      post[idx[a]] += b - m - 1;
    }

    // merge
    vector<int> tmp(j - i + 1);
    a = i, b = m + 1;
    int k = 0;
    while (a <= m && b <= j) {
      if (nums[idx[a]] <= nums[idx[b]]) {
        tmp[k++] = idx[a++];
      } else {
        tmp[k++] = idx[b++];
      }
    }
    while (a <= m) {
      tmp[k++] = idx[a++];
    }
    while (b <= j) {
      tmp[k++] = idx[b++];
    }

    for (int k = 0; k < j - i + 1; k++) {
      idx[i + k] = tmp[k];
    }
  }

public:
  int kBigIndices(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> pre(n, 0), post(n, 0), idx(n);
    iota(idx.begin(), idx.end(), 0);
    mergeSort(nums, idx, 0, n - 1, pre, post);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (pre[i] >= k && post[i] >= k) {
        cnt++;
      }
    }

    return cnt;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
