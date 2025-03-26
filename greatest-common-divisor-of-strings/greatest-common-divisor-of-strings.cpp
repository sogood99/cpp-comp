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
  string gcdOfStrings(string str1, string str2) {
    int m = str1.length(), n = str2.length();
    int t = min(m, n);

    string res;

    for (int i = 1; i <= t; i++) {
      if (m % i != 0 || n % i != 0) {
        continue;
      }
      // cout << i << endl;
      string s = str1.substr(0, i);
      bool match_1 = true;
      for (int k = 0; k < m / i; k++) {
        // cout << str1.substr(k * i, i) << " " << s << endl;
        if (str1.substr(k * i, i) != s) {
          match_1 = false;
          break;
        }
      }
      if (!match_1) {
        continue;
      }
      bool match_2 = true;
      for (int k = 0; k < n / i; k++) {
        // cout << s << " " << str2.substr(k*i, i) << endl;
        if (str2.substr(k * i, i) != s) {
          match_2 = false;
          break;
        }
      }
      if (!match_2) {
        continue;
      }

      res = s;
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
