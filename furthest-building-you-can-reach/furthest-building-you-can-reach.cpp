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
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    int total_bricks = 0, sum_of_ladder_h = 0, n = heights.size();

    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < n - 1; i++) {
      int diff = heights[i + 1] - heights[i];

      if (diff > 0) {
        total_bricks += diff;
        heap.push(diff);
        sum_of_ladder_h += diff;
        if (heap.size() > ladders) {
          int last = heap.top();
          heap.pop();
          sum_of_ladder_h -= last;
        }

        if (total_bricks - sum_of_ladder_h > bricks) {
          return i;
        }
      }
    }

    return n - 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
