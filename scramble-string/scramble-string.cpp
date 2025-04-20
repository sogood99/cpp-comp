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

typedef pair<string, string> strs;

class Solution {
  map<strs, bool> memo;

public:
  bool isScramble(string s1, string s2) {
    int n = s1.size();
    strs p = {s1, s2};

    if (memo.count(p)) {
      return memo[p];
    }

    if (n == 1) {
      return s1[0] == s2[0];
    }

    map<char, int> hm;

    // check if same char
    for (int i = 0; i < n; i++) {
      hm[s1[i]]++;
      hm[s2[i]]--;
    }
    for (auto &pr : hm) {
      if (pr.second != 0) {
        memo[p] = false;
        return false;
      }
    }

    bool canDo = false;
    for (int k = 1; k < n; k++) {
      canDo = isScramble(s1.substr(0, k), s2.substr(0, k)) &&
              isScramble(s1.substr(k, n), s2.substr(k, n));
      if (canDo) {
        memo[p] = true;
        return true;
      }

      canDo = isScramble(s1.substr(k, n - k), s2.substr(0, n - k)) &&
              isScramble(s1.substr(0, k), s2.substr(n - k, k));
      if (canDo) {
        memo[p] = true;
        return true;
      }
    }
    memo[p] = false;
    return memo[p];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
