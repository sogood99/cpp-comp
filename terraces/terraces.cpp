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

int s[510][510];

bool visited[510][510];
int n, m;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

inline bool check(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

int dfs(int i, int j) {
  queue<ii> q;
  int h = s[i][j], cnt = 0;
  q.push({i, j});
  visited[i][j] = true;

  bool flag = true;
  while (!q.empty()) {
    ii a = q.front();
    cnt++;

    for (int k = 0; k < 4; k++) {
      int x = a.first + dx[k], y = a.second + dy[k];
      if (check(x, y)) {
        if (s[x][y] == h && !visited[x][y]) {
          q.push({x, y});
          visited[x][y] = true;
        } else if (s[x][y] < h) {
          flag = false;
        }
      }
    }
    q.pop();
  }
  if (flag) {
    // cout << i << j << endl;
    return cnt;
  } else {
    return 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> s[i][j];
    }
  }
  fill_n(&visited[0][0], 510 * 510, false);

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        cnt += dfs(i, j);
      }
    }
  }
  cout << cnt << endl;

  return 0;
}
