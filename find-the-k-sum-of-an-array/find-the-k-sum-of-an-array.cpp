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
  long long kSum(vector<int> &nums, int k) {
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(0);

    vector<bool> inc(n, false);

    long long sm = 0;

    while (true) {
      int i = n - 1;

      while (i >= 0 && inc[i]) {
        inc[i] = false;
        sm -= nums[i];
        i--;
      }

      if (i < 0) {
        break;
      }

      inc[i] = true;
      sm += nums[i];

      pq.push(sm);

      if (pq.size() > k) {
        pq.pop();
      }
    }

    while (pq.size() > 1) {
      pq.pop();
    }

    return pq.top();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
