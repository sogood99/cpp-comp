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
  vector<string> reorderLogFiles(vector<string> &logs) {
    vector<int> digit;
    vector<pair<int, int>> letter; // first = index, second = identifier size

    int n = logs.size();

    for (int i = 0; i < n; i++) {
      string &s = logs[i];
      if (isdigit(s[s.size() - 1])) {
        digit.push_back(i);
      } else {
        int k = 0;
        while (s[k] != ' ') {
          k++;
        }

        letter.push_back({i, k});
      }
    }

    auto cmp = [&logs](pair<int, int> a, pair<int, int> b) {
      string &sa = logs[a.first], &sb = logs[b.first];
      string_view suba = string_view(sa).substr(a.second);
      string_view subb = string_view(sb).substr(b.second);

      if (suba == subb) {
        return sa < sb;
      }
      return suba < subb;
    };

    sort(letter.begin(), letter.end(), cmp);

    vector<string> res;
    for (auto p : letter) {
      string &s = logs[p.first];
      res.push_back(s);
    }

    for (auto i : digit) {
      res.push_back(logs[i]);
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
