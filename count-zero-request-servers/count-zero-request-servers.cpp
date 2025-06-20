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
  vector<int> countServers(int n, vector<vector<int>> &logs, int x,
                           vector<int> &queries) {

    vector<pair<int, int>> lgs;
    for (auto &l : logs) {
      lgs.push_back({l[1], l[0]});
    }

    sort(lgs.begin(), lgs.end());

    vector<int> res(queries.size());

    vector<pair<int, int>> t;

    for (int q = 0; q < queries.size(); q++) {
      t.push_back({queries[q], q});
    }
    sort(t.begin(), t.end());

    int i = 0, j = 0;

    unordered_map<int, int> freq;

    for (auto q : t) {
      int l = q.first - x, r = q.first;
      int k = q.second;
      while (j < lgs.size() && lgs[j].first <= r) {
        freq[lgs[j].second]++;
        j++;
      }

      while (i < j && lgs[i].first < l) {
        freq[lgs[i].second]--;
        if (freq[lgs[i].second] == 0) {
          freq.erase(lgs[i].second);
        }
        i++;
      }

      res[k] = n - freq.size();
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
