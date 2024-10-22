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

enum { UNVISITED = 0, EXPLORED = 1, VISITED = 2 };

int n, m;

vi dfs_nums, t;
vector<vi> al;

bool dfs(int u) {

  dfs_nums[u] = EXPLORED;

  for (const int v : al[u]) {
    if (dfs_nums[v] == UNVISITED) {
      if (dfs(v)) {
        return true;
      }
    } else if (dfs_nums[v] == EXPLORED) {
      return true;
    }
  }

  dfs_nums[u] = VISITED;

  t.push_back(u);

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  dfs_nums.assign(n + 10, UNVISITED);
  al.assign(n + 10, {});

  while (m--) {
    int a, b;
    cin >> a >> b;

    al[a].push_back(b);
  }

  for (int u = 1; u <= n; u++) {
    if (dfs_nums[u] == UNVISITED) {
      if (dfs(u)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }

  for (auto it = t.rbegin(); it != t.rend(); it++) {
    cout << *it << endl;
  }

  return 0;
}
