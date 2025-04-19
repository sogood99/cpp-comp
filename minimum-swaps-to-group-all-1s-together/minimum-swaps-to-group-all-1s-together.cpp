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

class Solution {
public:
  int minSwaps(vector<int> &data) {
    int n = data.size(), n_ones = 0;
    for (int d : data) {
      n_ones += d == 1 ? 1 : 0;
    }
    int min_zeros = 0, curr_zeros = 0;

    for (int i = 0; i < n_ones; i++) {
      curr_zeros += data[i] == 0 ? 1 : 0;
      min_zeros = curr_zeros;
    }

    for (int i = 1; i < n - n_ones; i++) {
      curr_zeros -= data[i] == 0 ? 1 : 0;
      curr_zeros += data[i + n_ones] == 0 ? 1 : 0;
      min_zeros = min(min_zeros, curr_zeros);
    }

    return min_zeros;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
