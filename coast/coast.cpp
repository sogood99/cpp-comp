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

int n, m;

char **mp;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

inline bool check(int i, int j) {
  return 0 <= i && i < n + 2 && 0 <= j && j < m + 2;
}

int flood_fill(int i, int j) {
  int coast = 0;

  vector<ii> fill_q;

  for (int k = 0; k < 4; k++) {
    int x = i + dx[k], y = j + dy[k];
    if (check(x, y)) {
      switch (mp[x][y]) {
      case '0':
        fill_q.push_back({x, y});
        mp[x][y] = '2';
        break;
      case '1':
        coast++;
      default:
        break;
      }
    }
  }

  for (auto [x, y] : fill_q) {
    coast += flood_fill(x, y);
  }

  return coast;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  mp = new char *[n + 10];

  for (int i = 1; i <= n; i++) {
    mp[i] = new char[m + 10];
    cin >> (mp[i] + 1);
    mp[i][0] = '0';
    mp[i][m + 1] = '0';
    mp[i][m + 2] = 0;
  }
  mp[0] = new char[m + 10];
  mp[n + 1] = new char[m + 10];

  fill_n(mp[0], m + 2, '0');
  fill_n(mp[n + 1], m + 2, '0');
  mp[0][m + 2] = 0;
  mp[n + 1][m + 2] = 0;

  // for (int i = 0; i <= n + 1; i++) {
  //   cout << mp[i] << endl;
  // }

  mp[0][0] = '2';
  int coast = flood_fill(0, 0);
  cout << coast << endl;

  return 0;
}
