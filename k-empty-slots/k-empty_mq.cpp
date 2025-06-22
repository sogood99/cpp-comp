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
  int kEmptySlots(vector<int> &bulbs, int k) {
    int n = bulbs.size();

    if (n <= k + 1) {
      return -1;
    }

    vector<int> t(n);

    for (int i = 0; i < n; i++) {
      t[bulbs[i] - 1] = i + 1;
    }

    deque<int> dq;

    for (int i = 0; i < k; i++) {
      while (!dq.empty() && t[dq.back()] > t[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }

    int mt = INT_MAX;

    for (int i = 0; i < n - k - 1; i++) {
      int l = i, r = i + k + 1;
      if (!dq.empty() && dq.front() <= l)
        dq.pop_front();

      while (!dq.empty() && t[dq.back()] > t[r - 1]) {
        dq.pop_back();
      }
      if (k > 0)
        dq.push_back(r - 1);

      int ot = max(t[l], t[r]);

      if (k == 0 || t[dq.front()] > ot) {
        mt = min(mt, ot);
      }
    }

    return mt == INT_MAX ? -1 : mt;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
