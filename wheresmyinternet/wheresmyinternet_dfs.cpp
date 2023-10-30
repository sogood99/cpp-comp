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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, e;
  cin >> n >> e;

  vector<vi> al(n + 10);
  vector<bool> visited(n + 10, false);
  stack<int> s;
  s.push(1);

  int f, t;
  for (int i = 0; i < e; i++) {
    cin >> f >> t;
    al[f].push_back(t);
    al[t].push_back(f);
  }

  int visit_cnt = 0;

  while (!s.empty()) {
    int u = s.top();
    s.pop();
    visited[u] = true;
    for (int w : al[u]) {
      if (!visited[w]) {
        s.push(w);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      cout << i << endl;
    } else {
      visit_cnt++;
    }
  }
  if (visit_cnt == n) {
    cout << "Connected" << endl;
  }

  return 0;
}
