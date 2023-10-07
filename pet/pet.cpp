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

  int n = 0, m_n = -1, m_v = -1;

  int t;
  for (int i = 1; i <= 5; i++) {
    int s = 0;
    for (int j = 0; j < 4; j++) {
      cin >> t;
      s += t;
    }
    if (s >= m_v) {
      m_n = i;
      m_v = s;
    }
  }
  cout << m_n << " " << m_v << endl;

  return 0;
}
