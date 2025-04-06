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
  vector<int> buildPrefix(const string &pt) {
    int n = pt.size();
    vector<int> prefix(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++) {
      while (j > 0 && pt[j] != pt[i])
        j = prefix[j - 1];

      if (pt[j] == pt[i])
        j++;

      prefix[i] = j;
    }
    return prefix;
  }

public:
  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> res;
    if (words.empty()) {
      return res;
    }
    int m = words[0].size(), n = s.size(), nw = words.size();

    vector<unordered_set<int>> matches(words.size());

    set<int> sp; // starting points

    for (int k = 0; k < nw; k++) {
      const string &pt = words[k];

      vector<int> prefix = buildPrefix(pt);

      int j = 0;

      for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != pt[j]) {
          j = prefix[j - 1];
        }

        if (s[i] == pt[j])
          j++;

        if (j == m) {
          matches[k].insert(i - m + 1);
          sp.insert(i - m + 1);
          j = prefix[j - 1];
        }
      }
    }

    for (int i : sp) {
      vector<bool> cnt(nw, false);

      int j = i, ms = 0;

      while (ms < nw) {
        bool matched = false;
        for (int k = 0; k < nw; k++) {
          if (!cnt[k] && matches[k].count(j)) {
            cnt[k] = true;
            matched = true;
            ms++;
            j += m;
            break;
          }
        }

        if (!matched) {
          break;
        }
      }

      if (ms == nw) {
        res.push_back(i);
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
