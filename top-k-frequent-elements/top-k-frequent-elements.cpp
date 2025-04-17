#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <queue>
#include <vector>

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
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    for (int n : nums) {
      freq[n]++;
    }
    vector<ii> v;

    for (pair<int, int> p : freq) {
      // freq n -> f
      v.emplace_back(p.second, p.first);
    }

    std::priority_queue<ii> pq(v.begin(), v.end());

    vector<int> res(k);
    for (int i = 0; i < k; i++) {
      res[i] = pq.top().second;
      pq.pop();
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
