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

  string s;
  cin >> s;
  vi v;

  int og = 0;
  for (char c : s) {
    v.push_back(c - '0');
    og = og * 10 + c - '0';
  }
  int mv = 1000000;

  do {
    int pv = 0;
    for (int i : v) {
      pv = pv * 10 + i;
    }
    if (pv > og) {
      mv = min(mv, pv);
    }
  } while (next_permutation(v.begin(), v.end()));

  mv == 1000000 ? (cout << 0 << endl) : (cout << mv << endl);

  return 0;
}
