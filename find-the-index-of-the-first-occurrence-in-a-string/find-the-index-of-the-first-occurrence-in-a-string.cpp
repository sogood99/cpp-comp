#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <string_view>

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
  int strStr(string haystack, string needle) {
    string_view s = haystack;

    int i = 0;

    while (s.length() >= needle.length()) {
      if (s.starts_with(needle)) {
        return i;
      }
      i++;
      s = s.substr(1, s.length() - 1);
    }

    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
