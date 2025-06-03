#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <vector>

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
private:
  vector<int> parse(string s) {
    int f = 0, t = 0, i = 0, n = s.size();

    bool start = false;

    while (i < n) {
      char c = s[i++];

      if (c == ':') {
        break;
      }

      f = f * 10 + (c - '0');
    }

    if (s[i] == 's') {
      start = true;
    }

    while (s[i++] != ':') {
    }

    while (i < n) {
      char c = s[i++];

      t = t * 10 + (c - '0');
    }

    return {f, start, t};
  }

public:
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    vector<int> total_time(n);
    vector<pair<int, int>> stk;

    for (string &l : logs) {
      vector<int> p = parse(l);

      int f = p[0], isStart = p[1], t = p[2];

      if (isStart) {
        stk.push_back({f, t});
      } else {
        auto [lf, lt] = stk.back();
        int l = t - lt + 1;
        total_time[f] += l;
        stk.pop_back();
        if (!stk.empty()) {
          auto [llf, lt] = stk.back();
          total_time[llf] -= l;
        }
      }
    }

    return total_time;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
