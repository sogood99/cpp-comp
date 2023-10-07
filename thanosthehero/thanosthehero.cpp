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

  int N;
  cin >> N;

  vll v;
  v.assign(N + 10, 0);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  ll count = 0;

  for (int i = N - 1; i > 0; i--) {
    if (v[i] < i) {
      cout << 1 << endl;
      return 0;
    } else {
      count += v[i - 1] - min(v[i - 1], v[i] - 1);
      v[i - 1] = min(v[i] - 1, v[i - 1]);
    }
  }
  cout << count << endl;
  return 0;
}
