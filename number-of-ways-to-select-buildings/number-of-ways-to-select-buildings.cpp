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
  long long numberOfWays(string s) {
    int n = s.size();
    vector<int> ol(n), rl(n);

    int oc = s[n - 1] == '0' ? 1 : 0, rc = s[n - 1] == '0' ? 0 : 1;

    for (int i = 1; i < n; i++) {
      if (s[i - 1] == '0') {
        ol[i] = ol[i - 1] + 1;
        rl[i] = rl[i - 1];
        oc++;
      } else {
        ol[i] = ol[i - 1];
        rl[i] = rl[i - 1] + 1;
        rc++;
      }
    }

    long long cnt = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == '0') {
        long long rlc = rl[i], rrc = rc - rl[i];
        cnt += rlc * rrc;
      } else {
        long long olc = ol[i], orc = oc - ol[i];
        cnt += olc * orc;
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
