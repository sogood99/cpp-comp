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
  bool mapsEqual(vector<int> &tchars, vector<int> &wchars) {
    for (int i = 0; i < 60; i++) {
      if (wchars[i] < tchars[i]) {
        return false;
      }
    }
    return true;
  }

public:
  string minWindow(string s, string t) {
    size_t m = s.size(), n = t.size();

    // unordered_map<char, int> tchars, wchars;
    vector<int> tchars(101, 0), wchars(101, 0);
    for (char c : t) {
      tchars[c - 'A']++;
    }
    int l = 0;

    int idx = -1, minSize = INT_MAX;

    for (int r = 0; r < m; r++) {
      wchars[s[r] - 'A']++;
      while (l <= r && mapsEqual(tchars, wchars)) {
        if (r - l + 1 < minSize) {
          minSize = r - l + 1;
          idx = l;
        }
        wchars[s[l] - 'A']--;
        l++;
      }
    }
    return idx == -1 ? "" : s.substr(idx, minSize);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
