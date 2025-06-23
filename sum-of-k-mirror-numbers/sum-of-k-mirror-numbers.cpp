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
private:
  bool isKMirror(long long v, int k) {
    long long rv = 0, t = v;

    while (t) {
      rv = rv * k + (t % k);
      t /= k;
    }

    return rv == v;
  }

  long long getval(vector<int> &v, int d) {
    long long ret = 0;
    if (d % 2 == 0) {
      for (int i = v.size() - 1; i >= 0; i--) {
        ret = ret * 10 + v[i];
      }
      for (int i = 0; i < v.size(); i++) {
        ret = ret * 10 + v[i];
      }
    } else {
      for (int i = v.size() - 1; i > 0; i--) {
        ret = ret * 10 + v[i];
      }
      ret = ret * 10 + v[0];
      for (int i = 1; i < v.size(); i++) {
        ret = ret * 10 + v[i];
      }
    }

    return ret;
  }

public:
  long long kMirror(int k, int n) {

    int d = 1, cnt = 0;
    long long s = 0;

    while (cnt < n) {
      vector<int> v((d + 1) / 2);
      v[v.size() - 1] = 1;

      vector<long long> k_mirror;

      while (true) {
        long long val = getval(v, d);
        if (v[v.size() - 1] > 0 && isKMirror(val, k)) {
          k_mirror.push_back(val);
        }

        int i = v.size() - 1;

        v[i]++;

        while (i >= 0 && v[i] >= 10) {
          v[i] = v[i] % 10;
          if (i > 0) {
            v[i - 1]++;
          }
          i--;
        }

        if (i < 0) {
          break;
        }
      }
      d++;
      sort(k_mirror.begin(), k_mirror.end());

      for (auto val : k_mirror) {
        s += val;
        cnt++;
        if (cnt == n) {
          break;
        }
      }
    }

    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
