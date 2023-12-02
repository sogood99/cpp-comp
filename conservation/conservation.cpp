#include <bits/extc++.h>
#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))
#define MN 100010

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

int n, m;
vector<vi> al(MN);
int cl[MN], deg[MN];

int topo_sort(int sc) {
  queue<int> pq_1, pq_2;
  int md[MN] = {0};

  for (int u = 1; u <= n; u++) {
    if (deg[u] == 0) {
      if (cl[u] == 1) {
        pq_1.push(u);
      } else {
        pq_2.push(u);
      }
    }
  }
  int cnt = -1;

  while (!pq_1.empty() || !pq_2.empty()) {

    for (int k = 0; k < 2; k++) {
      queue<int> &cpq =
          ((sc == 1 && k == 0) || (sc == 2 && k == 1) ? pq_1 : pq_2);

      if (!cpq.empty()) {
        cnt++;
        while (!cpq.empty()) {
          int u = cpq.front();
          cpq.pop();

          for (const auto &v : al[u]) {
            md[v]++;
            if (deg[v] - md[v] > 0)
              continue;

            if (cl[v] == 1) {
              pq_1.push(v);
            } else {
              pq_2.push(v);
            }
          }
        }
      }
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    cin >> n >> m;

    int l = 0, r = 0;

    for (int i = 1; i <= n; i++) {
      cin >> cl[i];
      al[i] = {};
      deg[i] = 0;
    }

    for (int i = 0; i < m; i++) {
      int f, t;
      cin >> f >> t;
      al[f].push_back(t);
      deg[t]++;
    }

    cout << min(topo_sort(1), topo_sort(2)) << endl;
  }

  return 0;
}
