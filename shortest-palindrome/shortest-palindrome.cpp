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
private:
  vector<int> buildPrefix(const string &s) {
    int n = s.size();
    vector<int> prefix(n, 0);
    int j = 0;

    for (int i = 1; i < n; i++) {
      while (j > 0 && s[i] != s[j])
        j = prefix[j - 1];

      if (s[i] == s[j])
        j++;

      prefix[i] = j;
    }

    return prefix;
  }

public:
  string shortestPalindrome(string s) {
    int n = s.size();
    string r = s;

    reverse(r.begin(), r.end());

    vector<int> prefix = buildPrefix(s);

    int m = 1;

    int j = 0;

    for (int i = 0; i < n; i++) {
      while (j > 0 && r[i] != s[j])
        j = prefix[j - 1];

      if (r[i] == s[j])
        j++;

      if (i == n - 1) {
        m = j;
      }
    }

    for (int i = m; i < n; i++) {
      r += s[i];
    }

    return r;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
