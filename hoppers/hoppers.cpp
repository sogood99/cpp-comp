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

const ll M = 500010;

enum { UNCOLORED = 0, RED = 1, BLACK = 2 };

// find cc, add cc - 1
// check if each cc is two colorable

int n, m;
vector<bool> visited(M, false);
vector<vi> al(M);

vi color(M, UNCOLORED);

int cc = 0;

inline int next_color(int c) { return 2 - (c - 1); }

bool bipartite(int s) {
  int c = RED;
  bool is_bipartite = true;

  queue<int> q;
  q.push(s);
  visited[s] = true;
  color[s] = BLACK;

  int l = 1, r = 0;

  while (l > 0 || r > 0) {
    if (l == 0) {
      l = r;
      r = 0;
      c = next_color(c);
    }

    int u = q.front();
    q.pop();
    for (const int v : al[u]) {
      if (!visited[v]) {
        visited[v] = true;
        color[v] = c;
        q.push(v);
        r++;
      } else if (color[v] != c) {
        is_bipartite = false;
      }
    }
    l--;
  }
  return is_bipartite;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    al[a].push_back(b);
    al[b].push_back(a);
  }

  bool has_ne_bip = false;

  for (int u = 1; u <= n; u++) {
    if (!visited[u]) {
      cc++;
      if (!bipartite(u)) {
        has_ne_bip = true;
      }
    }
  }
  cout << cc - 1 + (has_ne_bip ? 0 : 1) << endl;

  return 0;
}
