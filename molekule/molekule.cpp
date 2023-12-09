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

const ll N = 100010;

int n;
vector<vi> al(N);
vector<ii> e;
vi color(N, -1);
vi dir;

void bipartite(int s) {
  queue<int> q;
  q.push(s);

  color[s] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int j : al[u]) {
      if (dir[j] == -1) {
        if (e[j].first == u || e[j].second == u) {
          int v = (e[j].first == u ? e[j].second : e[j].first);

          dir[j] = ((color[u] == 0 && e[j].first == u) ||
                            (color[u] == 1 && e[j].second == u)
                        ? 0
                        : 1);

          if (color[v] == -1) {
            color[v] = 1 - color[u];
            q.push(v);
          }
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;

    al[a].push_back(i);
    al[b].push_back(i);
    e.push_back({a, b});
    dir.push_back(-1);
  }

  bipartite(1);

  for (int d : dir) {
    cout << d << endl;
  }

  return 0;
}
