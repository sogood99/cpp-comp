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
private:
  int canDecodeDigit(char c) {
    if (c == '0') {
      return 0;
    } else if (c == '*') {
      return 9;
    } else {
      return 1;
    }
  }
  // c1 == s[0], c2 == s[1]
  int canDecodeTwoDigit(char c1, char c2) {
    if (c1 == '*' && c2 == '*') {
      // 11-19 21-26
      return 15;
    } else if (c1 == '*') {
      // 1||c2 or 2||c2
      if (c2 <= '6') {
        return 2;
      } else {
        return 1;
      }

    } else if (c2 == '*') {
      // c1||[1-9]
      if (c1 == '0') {
        return 0;
      } else if (c1 == '1') {
        return 9;
      } else if (c1 == '2') {
        return 6;
      } else {
        return 0;
      }
    } else {
      if (c1 == '1') {
        return 1;
      } else if (c1 == '2') {
        return c2 <= '6' ? 1 : 0;
      } else {
        return 0;
      }
    }
  }

public:
  int numDecodings(string s) {
    // # of ways to decode dp[0..j] == dp[0..j-2] if decode(s[j-1..j]) possible
    //                              + dp[0..j-1] if decode(s[j]) possible
    // return decode s[n-1]
    if (s.size() == 0) {
      return 0;
    }
    int n = s.size();
    long long a, b, c;
    a = canDecodeDigit(s[0]);
    if (s.size() == 1) {
      return a;
    }
    b = canDecodeDigit(s[1]) * a;
    b += canDecodeTwoDigit(s[0], s[1]);

    for (int j = 2; j < n; j++) {
      c = canDecodeDigit(s[j]) * b;
      c += canDecodeTwoDigit(s[j - 1], s[j]) * a;
      c %= 1000000007;
      a = b;
      b = c;
    }
    return b;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
