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
  vector<int> findEvenNumbers(vector<int> &digits) {
    set<int> res;

    int n = digits.size();

    for (int i = 0; i < n; i++) {
      if (digits[i] == 0)
        continue;
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (i == j || j == k || k == i || digits[k] % 2 != 0)
            continue;

          res.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
        }
      }
    }

    return vector<int>(res.begin(), res.end());
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
