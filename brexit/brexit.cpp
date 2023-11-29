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

int n, m, X, L;
vector<vi> al;
int *p_count;

void bfs(int s) {
  std::queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : al[u]) {
      if (p_count[v] > 0) {
        p_count[v] -= 2;
        if (p_count[v] <= 0) {
          q.push(v);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> X >> L;

  if (X == L) {
    cout << "leave" << endl;
    return 0;
  }

  al.assign(n + 10, {});

  p_count = new int[n + 10];
  fill_n(p_count, n + 10, 0);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    al[u].push_back(v);
    al[v].push_back(u);

    p_count[u]++;
    p_count[v]++;
  }

  p_count[L] = 0;
  bfs(L);

  if (p_count[X] <= 0) {
    cout << "leave" << endl;
  } else {
    cout << "stay" << endl;
  }

  return 0;
}
