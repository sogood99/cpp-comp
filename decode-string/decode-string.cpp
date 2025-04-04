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

class Solution {
 public:
  string decodeString(string s) {
    string ret;
    int i = 0;
    while (i < s.length()) {
      if (isNum(s[i])) {
        pair<string, int> res = decode(s, i);
        ret += res.first;
        i = res.second;
      } else {
        ret += s[i];
        i++;
      }
    }
    return ret;
  }

  bool isNum(char c) {
    return c >= '0' && c <= '9';
  }

  pair<string, int> decode(string& s, int i) {
    string ret, curr;
    int cnt = 0;

    while (s[i] != '[') {
      cnt = cnt * 10 + (s[i] - '0');
      i++;
    }
    i++;
    while (s[i] != ']') {
      if (isNum(s[i])) {
        pair<string, int> res = decode(s, i);
        curr += res.first;
        i = res.second;
      } else {
        curr += s[i];
        i++;
      }
    }
    for (int j = 0; j < cnt; j++) {
      ret += curr;
    }
    return {ret, i + 1};
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;
  string str = "2[abc]3[cd]ef";

  cout << s.decodeString(str) << endl;

  return 0;
}
