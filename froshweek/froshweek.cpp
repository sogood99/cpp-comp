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

  int n;
  cin >> n;

  int *v = new int[n + 10];

  int i = 0, j = 1;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int cnt = 0;
  while (i < n) {
    for (; j < n && v[i] < v[j]; j++)
      ;
    if (j == n) {
      i++;
      j = i + 1;
    } else {
      swap(v[i], v[j]);
      cnt += (j - i);
      // cout << i << j << endl;
      // cout << v[i] << v[j] << endl;
    }
  }

  cout << cnt << endl;

  return 0;
}
