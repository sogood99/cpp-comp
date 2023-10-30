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
  ll n, m, l;

  cin >> n >> m >> l;

  vector<vll> al(n + 10);
  queue<ll> q;

  ll f, t;
  for (ll i = 0; i < m; i++) {
    cin >> f >> t;
    al[f].push_back(t);
  }

  ll cnt = 0;
  vll dist(n + 10, INF);
  for (ll i = 0; i < l; i++) {
    cin >> t;
    if (dist[t] != 0) {
      q.push(t);
      dist[t] = 0;
      cnt++;
    }
  }

  while (!q.empty()) {
    ll u = q.front();
    q.pop();
    for (ll w : al[u]) {
      if (dist[w] != INF)
        continue;
      dist[w] = dist[u] + 1;
      q.push(w);
      cnt++;
    }
  }
  cout << cnt << endl;
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
