#include <algorithm>
#include <bits/stdc++.h>

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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vi t(n), l(m);

  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> l[i];
  }

  sort(t.begin(), t.end());
  sort(l.begin(), l.end());

  int i = 0, j = 0, k = 0;
  while (i < n && j < m) {
    while (j < m && t[i] > l[j])
      j++;

    if (j == m)
      break;

    k++, i++, j++;
  }

  cout << k << endl;

  return 0;
}
