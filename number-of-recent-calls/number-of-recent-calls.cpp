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
const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18;  // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class RecentCounter {
 public:
  queue<int> q;
  RecentCounter() {
  }

  int ping(int t) {
    q.push(t);

    while (q.front() < t - 3000) {
      q.pop();
    }

    return q.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  RecentCounter rc;
  cout << rc.ping(1) << endl;    // return 1
  cout << rc.ping(100) << endl;  // return 2

  return 0;
}
