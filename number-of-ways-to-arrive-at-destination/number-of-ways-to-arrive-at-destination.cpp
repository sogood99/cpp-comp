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

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

class Solution {
private:
public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<pair<ll, ll>>> al;
    vector<vll> p;

    al.assign(n, {});
    p.assign(n, {});

    for (vi v : roads) {
      int a = v[0], b = v[1], w = v[2];

      al[a].push_back({b, w});
      al[b].push_back({a, w});
    }

    vll dist(n, INF);

    vll cnt(n, 0);
    dist[0] = 0;
    cnt[0] = 1;

    set<pair<ll, ll>> pq;
    for (int i = 0; i < n; i++) {
      pq.emplace(dist[i], i);
    }

    while (!pq.empty()) {
      auto [d, u] = *pq.begin();
      pq.erase(pq.begin());

      for (auto k : p[u]) {
        cnt[u] += cnt[k];
        cnt[u] = cnt[u] % MOD;
      }

      for (auto &[v, w] : al[u]) {
        if (dist[u] + w > dist[v]) {
          continue;
        } else if (dist[u] + w == dist[v]) {
          p[v].push_back(u);
          cnt[v] += cnt[u];
        } else {
          p[v].clear();
          p[v].push_back(u);

          cnt[v] = cnt[u];

          pq.erase(pq.find({dist[v], v}));
          dist[v] = dist[u] + w;
          pq.emplace(dist[v], v);
        }
      }
    }
    return cnt[n - 1];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
