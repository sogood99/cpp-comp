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
  int uniqueLetterString(string s) {
    int n = s.size();

    int total = 0;

    unordered_map<char, vector<int>> mp;

    for (char c = 'A'; c <= 'Z'; c++) {
      mp[c].push_back(-1);
    }

    for (int i = 0; i < n; i++) {
      mp[s[i]].push_back(i);
    }

    for (char c = 'A'; c <= 'Z'; c++) {
      mp[c].push_back(n);
    }

    //   i .....  m  ..... r
    //     m-i-1  *   r-m-1

    for (char c = 'A'; c <= 'Z'; c++) {
      vector<int> &idx = mp[c];
      for (int k = 0; k + 2 < idx.size(); k++) {
        int i = idx[k], m = idx[k + 1], r = idx[k + 2];

        total += (m - i) * (r - m);
      }
    }

    return total;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
