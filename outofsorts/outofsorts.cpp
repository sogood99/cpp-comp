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

ll n, m, a, c, x0;
vll v;

bool binary_search(ll sv) {
  ll l = 1, r = n, m;

  while (l <= r) {
    m = (l + r) / 2;

    if (v[m] == sv) {
      return true;
    } else if (v[m] > sv) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> a >> c >> x0;

  v.push_back(x0);

  for (int i = 0; i < n; i++) {
    ll nv = (a * v[i] + c) % m;
    v.push_back(nv);
  }

  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (binary_search(v[i])) {
      cnt++;
    } else {
    }
  }

  cout << cnt << endl;

  return 0;
}
