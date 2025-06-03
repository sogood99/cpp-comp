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
  int candy(vector<int> &ratings) {
    int n = ratings.size();

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&ratings](const int a, const int b) {
      return ratings[a] < ratings[b];
    });

    int total = 0;
    vector<int> candy(n);

    for (int i : idx) {
      candy[i] = 1;

      if (i - 1 >= 0 && ratings[i - 1] < ratings[i]) {
        candy[i] = candy[i - 1] + 1;
      }

      if (i + 1 < n && ratings[i + 1] < ratings[i]) {
        candy[i] = max(candy[i], candy[i + 1] + 1);
      }

      total += candy[i];
    }

    return total;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
