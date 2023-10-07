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

  vector<string> v;

  char s_c[55];
  cin >> s_c;

  string s = s_c;
  int n = s.size();

  v.push_back(s);

  for (int i = 1; i <= n - 2; i++) {
    for (int j = i + 1; j < n; j++) {
      string n_s = s;
      reverse(n_s.begin(), n_s.begin() + i);
      reverse(n_s.begin() + i, n_s.begin() + j);
      reverse(n_s.begin() + j, n_s.begin() + n);
      v.push_back(n_s);
    }
  }

  sort(v.begin(), v.end());

  cout << v[0] << endl;

  return 0;
}
