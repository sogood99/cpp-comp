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
  int longestRepeatingSubstring(string s) {
    if (s.empty())
      return 0;
    s += '$';
    int n = s.size();
    vector<int> SA(n), RK(n), tRK(n);

    for (int i = 0; i < n; i++) {
      SA[i] = i;
      RK[i] = s[i];
    }

    for (int k = 1; k < n; k >>= 1) {
      auto cmp = [&](const int a, const int b) {
        if (RK[a] != RK[b]) {
          return RK[a] < RK[b];
        }
        int ra = a + k < n ? RK[a + k] : -1;
        int rb = b + k < n ? RK[b + k] : -1;
        return ra < rb;
      };

      sort(SA.begin(), SA.end(), cmp);

      tRK[0] = 0;
      for (int i = 1; i < n; i++) {
        tRK[SA[i]] = tRK[SA[i - 1]] + (cmp(SA[i - 1], SA[i]) ? 1 : 0);
      }
      swap(tRK, RK);
    }

    vector<int> PHI(n), pLCP(n), LCP(n);
    for (int i = 1; i < n; i++) {
      PHI[SA[i]] = SA[i - 1];
    }
    PHI[SA[0]] = -1;

    int j = 0;
    for (int sa = 0; sa < n; sa++) {
      if (PHI[sa] == -1) {
        pLCP[sa] = 0;
        break;
      }
      while ((sa + j < n) && (PHI[sa] + j < n) && s[sa + j] == s[PHI[sa] + j])
        j++;

      pLCP[sa] = j;
      j = max(j - 1, 0);
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
      mx = max(pLCP[i], mx);
    }
    return mx;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
