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

class MedianFinder {
  multiset<double> small, large;
  // small has n/2, large has n/2[+1]

public:
  MedianFinder() {}

  void addNum(int num) {
    if (large.size() == 0) {
      large.insert(num);
    } else if (small.size() == large.size()) {
      // insert into large
      // [...l] [r...]
      double l = *small.rbegin(), r = *large.begin();
      if (num >= l) {
        large.insert(num);
      } else {
        small.erase(prev(small.end()));
        small.insert(num);
        large.insert(l);
      }
    } else {
      // try to balance
      double r = *large.begin();
      if (num <= r) {
        // balanced now
        small.insert(num);
      } else {
        large.erase(large.begin());
        small.insert(r);
        large.insert(num);
      }
    }
  }

  double findMedian() {
    if (large.size() == small.size()) {
      return (*prev(small.end()) + *large.begin()) / 2;
    } else {
      return *large.begin();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
