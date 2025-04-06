#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <string_view>

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
  bool hashMapMatches(unordered_map<string_view, int> &hm1,
                      unordered_map<string_view, int> &hm2) {

    bool matches = true;
    for (const auto &[ss, c] : hm1) {
      if (hm1[ss] != hm2[ss]) {
        matches = false;
        break;
      }
    }
    return matches;
  }

public:
  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> res;
    unordered_map<string_view, int> word_freq;
    int n = s.size(), m = words[0].size(), nw = words.size();

    string_view sw = s;

    for (const string &w : words) {
      word_freq[w]++;
    }

    for (int i = 0; i < m; i++) {
      if (i + nw * m > n) {
        break;
      }
      unordered_map<string_view, int> curr_word_freq;

      int r = i;

      for (int k = 0; k < nw; k++) {
        string_view ss = sw.substr(r, m);
        curr_word_freq[ss]++;
        r += m;
      }
      if (hashMapMatches(word_freq, curr_word_freq)) {
        res.push_back(i);
      }

      while (r + m <= n) {
        string_view ss = sw.substr(r - nw * m, m);
        curr_word_freq[ss]--;
        string_view ns = sw.substr(r, m);
        curr_word_freq[ns]++;

        if (hashMapMatches(word_freq, curr_word_freq)) {
          res.push_back(r - (nw - 1) * m);
        }

        r += m;
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
