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
  int minMeetingRooms(vector<vector<int>> &intervals) {

    vector<pair<int, int>> events;

    for (vector<int> &i : intervals) {
      events.push_back({i[0], +1});
      events.push_back({i[1], -1});
    }

    int z = 0, mz = 0;

    sort(events.begin(), events.end());

    int last_t = -1;

    for (auto [t, d] : events) {
      if (last_t != t) {
        mz = max(mz, z);
      }
      last_t = t;

      z += d;
    }

    return mz;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
