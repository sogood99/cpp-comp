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
const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18;  // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
 public:
  int compress(vector<char>& chars) {
    if (chars.size() == 0) {
      return 0;
    }

    int i = 0, j = 0, k = chars.size();
    char c;

    while (i < k) {
      int sz = 0;
      c = chars[i];
      while (i < k && chars[i] == c) {
        sz++;
        i++;
      }

      chars[j++] = c;
      if (sz != 1) {
        int l = j;
        while (sz > 0) {
          chars[j++] = '0' + (sz % 10);
          sz /= 10;
        }
        reverse(chars.begin() + l, chars.begin() + j);
      }
    }

    // chars.resize(j);
    return j;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

  int len = s.compress(chars);
  cout << "Length: " << len << endl;
  cout << "Compressed chars: ";
  for (int i = 0; i < len; i++) {
    cout << chars[i] << " ";
  }

  cout << endl;

  return 0;
}
