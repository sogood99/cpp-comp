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

void run() {
  int n, e;
  cin >> n >> e;

  vi dist(n + 10, INF);
  vector<vi> al(n + 10);

  int f, t;
  for (int i = 0; i < e; i++) {
    cin >> f >> t;
    al[f].push_back(t);
    al[t].push_back(f);
  }

  int cc = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] == INF) {
      cc++;
      queue<int> q;
      dist[i] = 0;
      q.push(i);

      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const int w : al[u]) {
          if (dist[w] != INF)
            continue;
          q.push(w);
          dist[w] = dist[u] + 1;
        }
      }
    }
  }

  cout << cc - 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    run();
  }

  return 0;
}
