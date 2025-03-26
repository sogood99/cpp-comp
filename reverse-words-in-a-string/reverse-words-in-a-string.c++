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
  string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int i = 0, r = 0, l = 0, n = s.length();
    while (i < n) {
      while (i < n && s[i] == ' ') {
        i++;
      }
      if (i == n) {
        break;
      }

      while (i < n && s[i] != ' ') {
        s[r++] = s[i++];
      }

      reverse(s.begin() + l, s.begin() + r);

      s[r++] = ' ';
      l = r;
    }
    s.resize(r - 1);
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
