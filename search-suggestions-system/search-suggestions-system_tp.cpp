#include <algorithm>
#include <bits/extc++.h>
#include <bits/stdc++.h>
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
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {

    sort(products.begin(), products.end());

    string pre;

    vector<vector<string>> res(searchWord.length());

    auto lb = products.begin(), ub = products.end();

    for (int i = 0; i < searchWord.length(); i++) {
      char c = searchWord[i];
      lb = lower_bound(lb, ub, pre + c);
      ub = lower_bound(lb, ub, pre + (char)(c + 1));
      pre += c;

      for (auto it = lb; it < ub; it++) {
        res[i].push_back(*it);
        if (res[i].size() == 3) {
          break;
        }
      }
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
