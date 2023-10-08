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

int val = 0;

set<int> s;

void backtrack(int r, int c) {
  if (r == 4 || c == 3 || r == 3 && c == 0 || r == 3 && c == 2) {
    s.insert(val);
    return;
  }

  if (val > 400) {
    return;
  }
  if (val == 0 && r == 3 && c == 1) {
    return;
  }

  // cout << r << " " << c << endl;

  backtrack(r + 1, c);
  backtrack(r, c + 1);

  if (r == 3 && c == 1)
    val = val * 10;
  else
    val = val * 10 + c + 1 + r * 3;

  backtrack(r, c);
  backtrack(r + 1, c);
  backtrack(r, c + 1);
  val /= 10;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, k;
  cin >> T;

  s.insert(0);
  backtrack(0, 0);
  // cout << "finished" << endl;

  while (T--) {
    cin >> k;
    auto it1 = s.lower_bound(k), it2 = it1;

    int closest = -500;
    if (it1 != s.begin()) {
      it1--;
      if (abs(closest - k) > abs(*it1 - k)) {
        closest = *it1;
      }
    }

    if (it2 != s.end()) {
      if (abs(closest - k) > abs(*it2 - k)) {
        closest = *it2;
      }
    }

    cout << closest << endl;
  }

  return 0;
}
