#include <bits/stdc++.h>
#include <set>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  set<int> s;

  int N;
  cin >> N;
  int root = -1, t;
  int *d = new int[N + 1];
  fill(d, d + N + 1, 0);
  ll td = 0;
  while (N--) {
    cin >> t;
    int cd = 0;
    if (root == -1) {
      root = t;
      s.insert(t);
      d[t] = 0;
    } else {
      s.insert(t);
      auto r = s.find(t), l = r;
      if (l != s.begin()) {
        l--;
        cd = d[*l];
      }
      if (r != s.end()) {
        r++;
        if (r != s.end()) {
          cd = max(cd, d[*r]);
        }
      }

      d[t] = cd + 1;
    }

    td += d[t];
    cout << td << endl;
  }

  return 0;
}
