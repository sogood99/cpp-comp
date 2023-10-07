#include <bits/stdc++.h>
#include <queue>

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

set<int> *s;
vi deg;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int v = n + 1;

  s = new set<int>[n + 10];
  deg.assign(n + 10, 0);

  struct {
    bool operator()(const int l, const int r) const {
      if (deg[l] < deg[r]) {
        return true;
      } else if (deg[l] == deg[r] && l < r) {
        return true;
      }
      return false;
    }
  } customLess;

  for (int i = 0; i < n; i++) {
  }

  return 0;
}
