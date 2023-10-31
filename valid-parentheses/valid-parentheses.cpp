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
private:
  map<char, char> mp;

public:
  bool isValid(string s) {
    stack<char> stk;
    mp[')'] = '(';
    mp[']'] = '[';
    mp['}'] = '{';
    for (char c : s) {
      switch (c) {
      case '(':
      case '{':
      case '[':
        stk.push(c);
        break;
      case ')':
      case ']':
      case '}':
        if (stk.top() == mp[c])
          stk.pop();
        else
          return false;
        break;
      }
    }
    return stk.empty();
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution().isValid("{{}}");

  return 0;
}
