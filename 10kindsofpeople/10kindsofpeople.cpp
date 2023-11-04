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

int r, c;
int s[1010][1010];
int ns[1010][1010];
bool visited[1010][1010] = {false};

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

inline bool check(int i, int j) { return i >= 0 && i < r && j >= 0 && j < c; }

int current = 2;
void flood_fill(int i, int j) {
  int cv = s[i][j];

  queue<ii> q;
  q.push({i, j});

  bool flag = false;
  while (!q.empty()) {
    ii t = q.front();
    q.pop();

    ns[t.first][t.second] = current;
    for (int l = 0; l < 4; l++) {
      int x = t.first + dx[l], y = t.second + dy[l];
      if (check(x, y) && !visited[x][y] && cv == s[x][y]) {
        visited[x][y] = true;
        q.push({x, y});
      }
    }
  }
  current++;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char t;
      cin >> t;
      s[i][j] = t - '0';
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (!visited[i][j])
        flood_fill(i, j);
    }
  }

  int n, i, j, u, v;
  cin >> n;
  for (int k = 0; k < n; k++) {
    cin >> i >> j >> u >> v;
    i--, j--, u--, v--;

    if (ns[i][j] != ns[u][v]) {
      cout << "neither" << endl;
    } else {
      cout << (s[i][j] == 0 ? "binary" : "decimal") << endl;
    }
  }

  return 0;
}
