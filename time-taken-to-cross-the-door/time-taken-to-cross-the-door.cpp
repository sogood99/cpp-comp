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
  vector<int> timeTaken(vector<int> &arrival, vector<int> &state) {
    queue<ii> pq_exit, pq_enter;

    int n = arrival.size(), t = 0, last_state = -1;

    for (int i = 0; i < n; i++) {
      if (state[i]) {
        pq_exit.emplace(arrival[i], i);
      } else {
        pq_enter.emplace(arrival[i], i);
      }
    }

    vector<int> res(n, 0);

    // simulate the process
    while (!pq_enter.empty() && !pq_exit.empty()) {
      auto [t_enter, i_enter] = pq_enter.front();
      auto [t_exit, i_exit] = pq_exit.front();
      t_enter = max(t_enter, t);
      t_exit = max(t_exit, t);

      if (t_enter > t && t_exit > t) {
        last_state = -1;
      }

      if (t_enter != t_exit) {
        if (t_enter < t_exit) {
          t = t_enter + 1;
          last_state = 0;
          pq_enter.pop();
          res[i_enter] = t_enter;
        } else {
          t = t_exit + 1;
          last_state = 1;
          pq_exit.pop();
          res[i_exit] = t_exit;
        }
      } else {
        if (last_state != 0) {
          // exit if last state != 0
          t = t_exit + 1;
          last_state = 1;
          pq_exit.pop();
          res[i_exit] = t_exit;
        } else {
          t = t_enter + 1;
          last_state = 0;
          pq_enter.pop();
          res[i_enter] = t_enter;
        }
      }
    }
    while (!pq_enter.empty()) {
      auto [t_enter, i_enter] = pq_enter.front();
      t_enter = max(t, t_enter);
      res[i_enter] = t_enter;
      t = t_enter + 1;
      pq_enter.pop();
    }
    while (!pq_exit.empty()) {
      auto [t_exit, i_exit] = pq_exit.front();
      t_exit = max(t, t_exit);
      res[i_exit] = t_exit;
      t = t_exit + 1;
      pq_exit.pop();
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
