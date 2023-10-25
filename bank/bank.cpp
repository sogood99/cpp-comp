// #include <bits/extc++.h>
#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Comparator {
public:
  bool operator()(ii x1, ii x2) {
    if (x1.first == x2.first) {
      return x1.second > x2.second;
    }
    return x1.first < x2.first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, T;
  cin >> n >> T;
  priority_queue<int, vi, greater<int>> pq;
  vii v;

  int c, t;
  for (int i = 0; i < n; i++) {
    cin >> c >> t;
    v.push_back({t, c});
  }
  sort(v.begin(), v.end(), Comparator());

  for (ii tc : v) {
    int t = tc.first, c = tc.second;
    if (pq.size() <= t) {
      pq.push(c);
    } else if (pq.top() < c) {
      pq.pop();
      pq.push(c);
    }
  }

  int sm = 0;
  while (!pq.empty()) {
    sm += pq.top();
    pq.pop();
  }
  cout << sm << endl;

  return 0;
}
