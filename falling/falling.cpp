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

  int D;

  cin >> D;

  for (int k = 1; k <= ceil(D / 2.); k++) {
    if (D % k == 0) {
      for (int n1 = 0; n1 <= ceil(D / 2. / k); n1++) {
        int n2 = D / k - n1;

        if (n2 >= n1 && 2 * n2 == k + D / k) {
          cout << n1 << " " << n2 << endl;
          return 0;
        }
      }
    }
  }

  cout << "impossible" << endl;

  return 0;
}
