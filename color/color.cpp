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

  int S, C, K;
  cin >> S >> C >> K;

  multiset<ii> ms;

  vi socks(S, 0);

  for (int i = 0; i < S; i++) {
    cin >> socks[i];
  }

  sort(socks.begin(), socks.end());

  int k = 0;

  for (int i = 0; i < S; i++) {
    auto it = ms.lower_bound({socks[i] - K, 0});
    ii v = *it;
    if (it == ms.end()) {
      // cout << socks[i] << " " << ms.begin()->first << ms.begin()->second
      //      << endl;
      if (C != 1) {
        ms.insert({socks[i], 1});
      }
      k++;
    } else {
      int col = it->first, cnt = it->second;
      // cout << socks[i] << "  " << col << " " << cnt << endl;
      ms.erase(it);
      if (cnt + 1 < C) {
        ms.insert({col, cnt + 1});
      }
    }
  }

  cout << k << endl;

  return 0;
}
