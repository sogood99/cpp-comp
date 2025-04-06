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
  int strStr(string haystack, string needle) {
    if (needle.empty()) {
      return -1;
    }

    vector<int> prefix = buildPrefix(needle);

    int n = haystack.length(), m = needle.length(), j = 0;

    for (int i = 0; i < n; i++) {
      while (j > 0 && haystack[i] != needle[j])
        j = prefix[j - 1];

      if (haystack[i] == needle[j])
        j++;

      if (j == m) {
        return i + 1 - m;
      }
    }
    return -1;
  }

private:
  vector<int> buildPrefix(const string &pattern) {
    int m = pattern.length();
    vector<int> prefix(m, 0);

    int j = 0;
    for (int i = 1; i < m; i++) {
      while (j > 0 && pattern[j] != pattern[i])
        j = prefix[j - 1];
      if (pattern[j] == pattern[i])
        j++;

      prefix[i] = j;
    }

    return prefix;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
