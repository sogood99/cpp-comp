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
  string predictPartyVictory(string senate) {
    queue<char> q;

    int rn = 0, dn = 0, rb = 0, db = 0;

    for (char c : senate) {
      q.push(c);
      if (c == 'R') {
        rn++;
      } else {
        dn++;
      }
    }

    while (true) {
      if (dn == 0) {
        return "Radiant";
      } else if (rn == 0) {
        return "Dire";
      }

      char c = q.front();
      q.pop();
      if (c == 'R') {
        if (rb > 0) {
          rb--;
          rn--;
        } else {
          db++;
          q.push(c);
        }
      } else {
        if (db > 0) {
          db--;
          dn--;
        } else {
          rb++;
          q.push(c);
        }
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
