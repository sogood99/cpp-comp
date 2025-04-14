#include <algorithm>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  s += '$';

  int n = s.size();

  vector<int> SA(n), RA(n), tRA(n);

  vector<string> ss;

  for (int i = 0; i < n; i++) {
    ss.push_back(s.substr(i, n - i));
  }

  for (int i = 0; i < n; i++) {
    SA[i] = i;
    RA[i] = s[i];
  }

  for (int k = 1; k < n; k *= 2) {
    auto cmp = [&](const int a, const int b) {
      if (RA[a] != RA[b])
        return RA[a] < RA[b];
      int ra = (a + k < n) ? RA[a + k] : -1;
      int rb = (b + k < n) ? RA[b + k] : -1;
      return ra < rb;
    };
    sort(SA.begin(), SA.end(), cmp);

    tRA[SA[0]] = 0;
    for (int j = 1; j < n; j++) {
      tRA[SA[j]] = tRA[SA[j - 1]] + (cmp(SA[j - 1], SA[j]) ? 1 : 0);
    }
    swap(RA, tRA);
  }

  for (int i = 0; i < n; i++) {
    cout << SA[i] << " " << ss[SA[i]] << endl;
  }

  // find occurences
  int k;
  cin >> k;
  for (int l = 0; l < k; l++) {
    string t;
    cin >> t;

    int m = t.size();
    auto lit = SA.begin(), rit = SA.end();
    for (int j = 0; j < m; j++) {
      auto tlit = lower_bound(lit, rit, t[j],
                              [&](const int a, const char c) {
                                return a + j < n ? s[a + j] < c : true;
                              }),
           trit = upper_bound(lit, rit, t[j], [&](const char c, const int a) {
             return a + j < n ? c < s[a + j] : false;
           });
      cout << tlit - SA.begin() << " " << trit - SA.begin() << endl;
      lit = tlit, rit = trit;
    }

    for (auto it = lit; it != rit; it++) {
      cout << "Occurence: " << *it << endl;
    }
  }

  // construct LCP

  vector<int> LCP(n), PHI(n), PLCP(n);
  for (int i = 1; i < n; i++) {
    PHI[SA[i]] = SA[i - 1];
  }
  PHI[SA[0]] = -1;

  for (int i = 0, L = 0; i < n; i++) {
    if (PHI[i] == -1) {
      PLCP[i] = 0; // $
      continue;
    }
    while ((i + L < n) && (PHI[i] + L < n) && (s[i + L] == s[PHI[i] + L]))
      L++;

    PLCP[i] = L;
    L = max(L - 1, 0);
  }

  for (int i = 0; i < n; i++) {
    LCP[i] = PLCP[SA[i]];
  }

  cout << "LCP[i]" << endl;
  for (int i = 0; i < n; i++) {
    cout << SA[i] << " " << ss[SA[i]] << " " << LCP[i] << endl;
  }

  return 0;
}
