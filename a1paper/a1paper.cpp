#include <bits/stdc++.h>
#include <future>
#include <iomanip>

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

double paperl = pow(2.0, -3 / 4.), papers = pow(2.0, -5 / 4.);

int n;
vi v;

double total = 0;

bool backtrack(int i, int count) {
  total += paperl * (count / 2.);
  swap(paperl, papers);
  papers /= 2;
  if (n == i) {
    return false;
  } else if (v[i] >= count) {
    return true;
  } else {
    return backtrack(i + 1, 2 * (count - v[i]));
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  n--;
  v.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  if (backtrack(0, 2)) {
    cout << setprecision(20) << total << endl;
  } else {
    cout << "impossible" << endl;
  }

  return 0;
}
