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
  vector<string> topKFrequent(vector<string> &words, int k) {
    map<string, int> freq;

    for (auto &w : words) {
      freq[w]++;
    }

    priority_queue<pair<int, string>> pq;
    for (auto &p : freq) {
      pq.push({-p.second, p.first});
      if (pq.size() > k)
        pq.pop();
    }

    vector<string> res;

    while (!pq.empty()) {
      string s = pq.top().second;
      pq.pop();
      res.push_back(s);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
