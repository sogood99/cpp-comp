#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  scanf("%d %d\n", &n, &k);

  // priority_queue<ii, vector<ii>, greater<ii>> v;
  // vii v;
  ii *v = new ii[n + 1];
  // v.assign(n, {0, 0});

  ii t;
  for (int i = 0; i < n; i++) {
    scanf("%d %d\n", &t.second, &t.first);
    v[i] = t;
  }

  sort(v, v + n);

  // multiset<int, greater<int>> pq;
  multiset<int, greater<int>> pq;
  // for (int i = 0; i < k; i++) {
  //   pq.insert(0);
  // }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int st = v[i].second;

    // auto it = pq.begin();
    auto it = pq.upper_bound(st);
    // while (it != pq.end()) {
    if (it != pq.end()) {
      // cout << st << it->first << endl;
      pq.erase(it);
      pq.insert(v[i].first);
      cnt++;
      // break;
    } else if (pq.size() < k) {
      pq.insert(v[i].first);
      cnt++;
    }
    //   it++;
    // }
  }

  printf("%d\n", cnt);

  return 0;
}
