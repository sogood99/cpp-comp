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
  string pushDominoes(string dominoes) {
    vector<char> stk;

    char last_action = 0;
    int sz = 0;
    for (char c : dominoes) {
      if (last_action == 0) {
        if (c == 'L') {
          for (int i = 0; i < sz + 1; i++) {
            stk.push_back('L');
          }
          sz = 0;
          last_action = c;
        } else if (c == 'R') {
          for (int i = 0; i < sz; i++) {
            stk.push_back('.');
          }
          stk.push_back('R');
          sz = 0;
          last_action = c;
        } else {
          sz++;
        }
      } else if (last_action == 'L') {
        if (c == '.') {
          sz++;
          continue;
        }

        if (c == 'L') {
          for (int i = 0; i < sz + 1; i++) {
            stk.push_back('L');
          }
        } else if (c == 'R') {
          for (int i = 0; i < sz; i++) {
            stk.push_back('.');
          }
          stk.push_back('R');
        }
        sz = 0;
        last_action = c;
      } else if (last_action == 'R') {
        if (c == '.') {
          sz++;
          continue;
        }

        if (c == 'L') {
          for (int i = 0; i < sz / 2; i++) {
            stk.push_back('R');
          }
          if (sz % 2)
            stk.push_back('.');
          for (int i = 0; i < sz / 2; i++) {
            stk.push_back('L');
          }
          stk.push_back('L');
        } else if (c == 'R') {
          for (int i = 0; i < sz + 1; i++) {
            stk.push_back('R');
          }
        }
        sz = 0;
        last_action = c;
      }
    }

    if (last_action != 'R') {
      for (int i = 0; i < sz; i++) {
        stk.push_back('.');
      }
    } else {
      for (int i = 0; i < sz; i++) {
        stk.push_back('R');
      }
    }

    string res(stk.begin(), stk.end());

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
