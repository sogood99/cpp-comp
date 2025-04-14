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
  string longestDupSubstring(string s) {
    s += '$';
    size_t n = s.size();

    vi SA(n), RA(n), tRA(n);
    iota(SA.begin(), SA.end(), 0);

    for (int i = 0; i < n; i++) {
      RA[i] = s[i];
    }

    for (int k = 1; k < n; k *= 2) {
      auto cmp = [&](const int a, const int b) {
        if (RA[a] != RA[b]) {
          return RA[a] < RA[b];
        }
        int ra = a + k < n ? RA[a + k] : -1;
        int rb = b + k < n ? RA[b + k] : -1;
        return ra < rb;
      };

      sort(SA.begin(), SA.end(), cmp);

      tRA[0] = 0;
      for (int i = 1; i < n; i++) {
        tRA[SA[i]] = tRA[SA[i - 1]] + (cmp(SA[i - 1], SA[i]) ? 1 : 0);
      }
      swap(tRA, RA);
    }

    vector<int> LCP(n), PHI(n), PLCP(n);
    for (int i = 1; i < n; i++) {
      PHI[SA[i]] = SA[i - 1];
    }
    PHI[SA[0]] = -1;

    for (int si = 0, L = 0; si < n; si++) {
      if (PHI[si] == -1) {
        PLCP[si] = 0;
        break;
      }

      while ((si + L < n) && (PHI[si] + L < n) && (s[si + L] == s[PHI[si] + L]))
        L++;

      PLCP[si] = L;
      L = max(L - 1, 0);
    }

    int mx = 0, midx = -1;
    for (int i = 0; i < n; i++) {
      LCP[i] = PLCP[SA[i]];
      if (LCP[i] > mx) {
        mx = LCP[i];
        midx = SA[i];
      }
    }

    return s.substr(midx, mx);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
