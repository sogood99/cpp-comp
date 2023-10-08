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

vector<vll> v;
int N;

bool can(ll k) {
  for (vll vt : v) {
    int i = 0, j = 1;
    while (i < N && vt[i] <= k)
      i++;

    while (i < N) {
      j = i + 1;
      while (j < N && vt[j] <= k)
        j++;
      if (j >= N) {
        return false;
      }
      // cout << k << vt[i] << vt[j] << endl;

      if (vt[i] != vt[j]) {
        return false;
      }
      i = j + 1;
      while (i < N && vt[i] <= k)
        i++;
    }
  }
  return true;
}

ll bins(ll l, ll r) {
  while (l <= r) {
    if (r - l <= 1) {
      if (can(l)) {
        return l;
      }
      return r;
    }

    ll m = l + (r - l) / 2;
    if (can(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  ll maxv = 0;

  for (int j = 0; j < 2; j++) {
    vll t;
    t.assign(N, 0);
    for (int i = 0; i < N; i++) {
      cin >> t[i];
      maxv = max(maxv, t[i]);
    }

    v.push_back(t);
  }

  cout << bins(0, maxv) << endl;

  return 0;
}
