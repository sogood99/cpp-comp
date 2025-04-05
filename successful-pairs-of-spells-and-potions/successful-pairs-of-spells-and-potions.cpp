#include <algorithm>
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>

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
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {

    size_t n = spells.size(), m = potions.size();
    vector<int> pairs(spells.size());

    sort(potions.begin(), potions.end());

    for (int i = 0; i < n; i++) {
      pairs[i] = distance(lower_bound(potions.begin(), potions.end(),
                                      ceil(success / (double)spells[i])),
                          potions.end());
    }

    return pairs;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
