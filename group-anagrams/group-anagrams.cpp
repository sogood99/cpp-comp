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
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    int n = strs.size();
    vector<int> parent(n);

    auto cmp = [&strs](int a, int b) { return strs[a] < strs[b]; };

    set<int, decltype(cmp)> st(cmp);

    for (int j = 0; j < n; j++) {
      bool isequal = false;
      string s = strs[j];

      sort(strs[j].begin(), strs[j].end());

      auto it = st.lower_bound(j);

      if (it != st.end() && strs[*it] == strs[j]) {
        parent[j] = parent[*it];
        res[parent[j]].push_back(s);
        isequal = true;
      }
      st.insert(j);

      if (!isequal) {
        parent[j] = res.size();
        res.push_back({s});
      }
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  Solution s;
  s.groupAnagrams(strs);

  return 0;
}
