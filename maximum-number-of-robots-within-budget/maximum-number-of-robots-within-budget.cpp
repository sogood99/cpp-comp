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
  int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts,
                    long long budget) {
    int i = 0, n = chargeTimes.size();
    long long sm = 0;

    deque<int> mq;

    int mx = 0;

    for (int j = 0; j < n; j++) {
      // cost = max(chargeTime) + k * sum(runningCosts);

      while (!mq.empty() && chargeTimes[mq.back()] < chargeTimes[j]) {
        mq.pop_back();
      }
      mq.push_back(j);
      sm += runningCosts[j];

      long long cost = chargeTimes[mq.front()] + (j - i + 1) * sm;

      while (i < j && j - i + 1 > mx && cost > budget) {
        if (mq.front() == i) {
          mq.pop_front();
        }
        sm -= runningCosts[i];

        i++;
        cost = chargeTimes[mq.front()] + (j - i + 1) * sm;
      }

      if (cost <= budget) {
        mx = j - i + 1;
      }
    }

    return mx;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
