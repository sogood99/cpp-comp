#include <bits/stdc++.h>
#include <unordered_set>

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

  int N, M;
  while (1) {
    cin >> N >> M;
    if (N == M && N == 0) {
      return 0;
    }

    unordered_set<int> us;

    int t;
    while (N--) {
      cin >> t;
      us.insert(t);
    }

    int c = 0;
    while (M--) {
      cin >> t;
      if (us.count(t) >= 1) {
        c++;
      }
    }
    cout << c << endl;
  }
  return 0;
}
