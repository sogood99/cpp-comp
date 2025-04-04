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
  int maxArea(vector<int>& height) {
    size_t n = height.size();
    int l = 0, r = n - 1, max_area = 0;
    while (l < r) {
      max_area = max(max_area, (r - l) * min(height[l], height[r]));

      if (height[l] > height[r]) {
        r--;
      } else {
        l++;
      }
    }
    return max_area;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  cout << s.maxArea(height) << endl;

  // verify

  for (int i = 0; i < height.size(); i++) {
    for (int j = i + 1; j < height.size(); j++) {
      int area = (j - i) * min(height[i], height[j]);
      cout << "area(" << i << ", " << j << ") = " << area << endl;
    }
  }

  return 0;
}
