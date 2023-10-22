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

  int N;
  cin >> N;

  vii est;
  est.assign(N, {0, 0});

  int l, r;
  for (int i = 0; i < N; i++) {
    cin >> l >> r;

    est[i] = {r, l};
  }
  sort(est.begin(), est.end());

  auto it = est.begin();
  while (it != est.end()) {
    if (it != est.begin() && it->second <= (it - 1)->first) {
      it = est.erase(it);
    } else {
      it++;
    }
  }
  cout << est.size() << endl;
  return 0;
}
