#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <queue>

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, e;
  cin >> n >> e;

  int conn_cnt = 0;
  vector<vi> al(n + 10);

  int f, t;
  for (int i = 0; i < e; i++) {
    cin >> f >> t;
    al[f].push_back(t);
    al[t].push_back(f);
  }

  vi dist(n + 10, INF);
  dist[1] = 0;
  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int w : al[u]) {
      if (dist[w] != INF)
        continue;
      dist[w] = dist[u] + 1;
      conn_cnt++;
      q.push(w);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dist[i] == INF) {
      cout << i << endl;
    }
  }
  if (conn_cnt == n - 1) {
    cout << "Connected" << endl;
  }

  return 0;
}
