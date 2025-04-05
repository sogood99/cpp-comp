#include <bits/extc++.h>
#include <bits/stdc++.h>

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

class SmallestInfiniteSet {
public:
  set<int> pq;
  SmallestInfiniteSet() { pq.insert(1); }

  int popSmallest() {
    int k = *pq.begin();
    if (pq.size() == 1) {
      pq.insert(k + 1);
    }
    pq.erase(pq.begin());
    return k;
  }

  void addBack(int num) {
    int l = *pq.rbegin();
    if (num < l && pq.count(num) == 0) {
      pq.insert(num);
    }
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
