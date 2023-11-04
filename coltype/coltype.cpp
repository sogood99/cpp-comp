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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  reverse(s.begin(), s.end());

  int n = s.size();

  for (char c : s) {
    if (c != 'O' && c != 'E') {
      cout << "INVALID" << endl;
      return 0;
    }
  }
  if (s[0] != 'O') {
    cout << "INVALID" << endl;
    return 0;
  }

  ll mv = LLINF;

  for (ll k = 1; k < LLINF; k *= 2) {
    ll c = k;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'O') {
        if ((c - 1) % 3 == 0) {
          c = (c - 1) / 3;
        } else {
          flag = true;
          break;
        }
        if (c % 2 != 1) {
          flag = true;
          break;
        }
      } else {
        if (c == LSOne(c)) {
          flag = true;
          break;
        } else {
          c *= 2;
        }

        if (c < 0 || c % 2 != 0) {
          flag = true;
          break;
        }
      }
    }
    // cout << k << " " << c << endl;
    if (!flag) {
      mv = min(c, mv);
    }
  }

  if (mv > (1ll << 47)) {
    cout << "INVALID" << endl;
  } else {
    cout << mv << endl;
  }

  return 0;
}
