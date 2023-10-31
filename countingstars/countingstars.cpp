#include <bits/extc++.h>
#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

int m, n;
vector<string> s;

vi dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

inline bool check(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }

void flood_fill(int i, int j) {
  s[i][j] = '@';

  for (int k = 0; k < 4; k++) {
    int x = i + dx[k], y = j + dy[k];
    if (check(x, y) && s[x][y] == '-') {
      flood_fill(x, y);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 0;
  while (cin >> m >> n) {
    s = vector<string>(m);
    for (int i = 0; i < m; i++) {
      cin >> s[i];
    }
    t++;
    int cc = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == '-') {
          flood_fill(i, j);
          cc++;
        }
      }
    }
    cout << "Case " << t << ": " << cc << endl;
  }

  return 0;
}
