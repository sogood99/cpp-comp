#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <deque>
#include <ios>
#include <numeric>

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
  vector<int> goodDaysToRobBank(vector<int> &sec, int time) {
    // left_mq of size at most "time", contains index and also decreasing
    // right_mq of size at most "time", contains index ''      increasing
    // block size of 2 * time + 1
    // add in sec[i + time - 1] to left_mq, add in sec[i + 2 * time]

    // [i .. i+time-1] [i + time] [i+time+1 .. i + 2*time]

    int n = sec.size();

    if (n < 2 * time + 1) {
      return {};
    }

    if (time == 0) {
      vector<int> res(n);
      iota(res.begin(), res.end(), 0);
      return res;
    }

    deque<int> left_mq, right_mq;

    for (int i = 0; i < time - 1; i++) {
      while (!left_mq.empty() && sec[left_mq.back()] < sec[i]) {
        left_mq.pop_back();
      }
      left_mq.push_back(i);
    }

    for (int i = time + 1; i < 2 * time; i++) {
      while (!right_mq.empty() && sec[right_mq.back()] > sec[i]) {
        right_mq.pop_back();
      }
      right_mq.push_back(i);
    }

    vector<int> res;
    for (int i = 0; i < n - 2 * time; i++) {
      if (!left_mq.empty() && left_mq.front() < i) {
        left_mq.pop_front();
      }
      if (!right_mq.empty() && right_mq.front() <= i + time) {
        right_mq.pop_front();
      }

      while (!left_mq.empty() && sec[left_mq.back()] < sec[i + time - 1]) {
        left_mq.pop_back();
      }
      left_mq.push_back(i + time - 1);

      while (!right_mq.empty() && sec[right_mq.back()] > sec[i + 2 * time]) {
        right_mq.pop_back();
      }
      right_mq.push_back(i + 2 * time);

      int m = sec[i + time];

      if (left_mq.size() == time && right_mq.size() == time &&
          sec[left_mq.back()] >= m && sec[right_mq.front()] >= m) {
        res.push_back(i + time);
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
