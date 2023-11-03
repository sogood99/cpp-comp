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
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() < b.size())
      swap(a, b);

    int n = b.size(), m = a.size();
    int carry = 0, res = 0;
    for (int i = 0; i < n; i++) {
      res = a[i] + b[i] - 2 * '0' + carry;
      a[i] = (res % 2) + '0';
      carry = res / 2;
    }

    for (int i = n; i < m; i++) {
      res = a[i] - '0' + carry;
      a[i] = (res % 2) + '0';
      carry = res / 2;
      if (carry == 0)
        break;
    }
    if (carry)
      a.push_back('1');
    reverse(a.begin(), a.end());
    return a;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << Solution().addBinary("111", "1");

  return 0;
}
