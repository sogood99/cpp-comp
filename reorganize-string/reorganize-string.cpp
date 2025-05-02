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
  string reorganizeString(string s) {
    int n = s.size();
    vector<int> cnt(26);
    for (char c : s) {
      cnt[c - 'a']++;

      if (cnt[c - 'a'] > (n + 1) / 2) {
        return "";
      }
    }

    priority_queue<pair<int, char>> pq;
    for (char c = 'a'; c <= 'z'; c++) {
      if (cnt[c - 'a'] > 0)
        pq.push({cnt[c - 'a'], c});
    }

    int i = 0;
    while (!pq.empty()) {
      auto [k, c] = pq.top();
      pq.pop();
      s[i++] = c;

      if (!pq.empty()) {
        auto [k2, c2] = pq.top();
        pq.pop();
        s[i++] = c2;
        k2--;

        if (k2 > 0)
          pq.push({k2, c2});
      }

      k--;
      if (k > 0)
        pq.push({k, c});
    }

    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  cout << s.reorganizeString("aab") << endl;

  return 0;
}
