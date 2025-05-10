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
  int minimumOperations(vector<int> &nums) {
    unordered_map<int, int> freq_even, freq_odd;

    int n = nums.size();

    if (n == 1) {
      return 0;
    }

    for (int i = 0; i < n; i += 2) {
      freq_even[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq_even, pq_odd;

    for (auto &p : freq_even) {
      pq_even.push({p.second, -p.first});
      if (pq_even.size() > 2) {
        pq_even.pop();
      }
    }

    for (int i = 1; i < n; i += 2) {
      freq_odd[nums[i]]++;
    }

    for (auto &p : freq_odd) {
      pq_odd.push({p.second, p.first});
      if (pq_odd.size() > 2) {
        pq_odd.pop();
      }
    }

    int num_even = (n + 1) / 2, num_odd = n / 2;

    int sbest_even = -1, sbest_even_freq = 0, best_even = -1,
        best_even_freq = 0, sbest_odd = -1, sbest_odd_freq = 0, best_odd = -1,
        best_odd_freq = 0;

    if (pq_even.size() == 2) {
      sbest_even = -pq_even.top().second, sbest_even_freq = pq_even.top().first;
      pq_even.pop();
      best_even = -pq_even.top().second, best_even_freq = pq_even.top().first;
      pq_even.pop();
    } else {
      best_even = -pq_even.top().second, best_even_freq = pq_even.top().first;
      pq_even.pop();
    }
    if (pq_odd.size() == 2) {
      sbest_odd = pq_odd.top().second, sbest_odd_freq = pq_odd.top().first;
      pq_odd.pop();
      best_odd = pq_odd.top().second, best_odd_freq = pq_odd.top().first;
      pq_odd.pop();
    } else {
      best_odd = pq_odd.top().second, best_odd_freq = pq_odd.top().first;
      pq_odd.pop();
    }

    if (best_even != best_odd) {
      return num_even - best_even_freq + num_odd - best_odd_freq;
    } else {
      return min(num_even - sbest_even_freq + num_odd - best_odd_freq,
                 num_odd - sbest_odd_freq + num_even - best_even_freq);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
