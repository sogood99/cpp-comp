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
  vector<string> mostVisitedPattern(vector<string> &username,
                                    vector<int> &timestamp,
                                    vector<string> &website) {

    set<string> users(username.begin(), username.end());

    map<string, set<pair<int, string>>> hm;

    int n = username.size();

    for (int i = 0; i < n; i++) {
      hm[username[i]].insert({timestamp[i], website[i]});
    }

    map<string, set<vector<string>>> mp;

    for (const string &user : users) {
      auto &st = hm[user];
      auto &mpst = mp[user];
      for (auto it = st.begin(); it != st.end(); it++) {
        if (next(it, 2) == st.end())
          break;
        for (auto jt = next(it); jt != st.end(); jt++) {
          if (next(jt) == st.end())
            break;
          for (auto kt = next(jt); kt != st.end(); kt++) {

            mpst.insert({it->second, jt->second, kt->second});
          }
        }
      }
    }

    map<vector<string>, int> freq;

    for (const string &user : users) {
      auto &mpst = mp[user];
      for (const vector<string> &v : mpst) {
        freq[v]++;
      }
    }

    if (freq.size() == 0)
      return {};

    vector<string> best_v;
    int best_freq = -1;

    for (auto &p : freq) {
      if (p.second > best_freq || (p.second == best_freq && p.first < best_v)) {
        best_freq = p.second;
        best_v = p.first;
      }
    }

    return best_v;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
