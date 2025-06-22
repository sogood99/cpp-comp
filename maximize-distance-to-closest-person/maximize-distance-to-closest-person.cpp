#include <bits/extc++.h>
#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
public:
  int maxDistToClosest(vector<int> &seats) {
    int n = seats.size();
    vector<int> idx;

    for (int i = 0; i < n; i++) {
      if (seats[i])
        idx.push_back(i);
    }

    int j = 0;

    int d = 0;

    for (int i = 0; i < n; i++) {
      while (idx[j] <= i && j + 1 < idx.size()) {
        j++;
      }

      if (seats[i] == 0) {
        if (idx[j] > i) {
          int cd = min(idx[j] - i, j > 0 ? i - idx[j - 1] : INT_MAX);
          d = max(d, cd);
        } else {
          d = max(d, i - idx[j]);
        }
      }
    }

    return d;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
