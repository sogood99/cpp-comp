#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

// Shortcuts for "common" constants
const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18;  // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int i = 0, j = 0, c = 0, n = nums.size(), l = 0;
    while (c < k && j < n) {
      c += 1 - nums[j++];
    }
    l = j - i;

    while (j < n) {
      cout << i << " " << j << " " << c << endl;
      if (c == k && nums[j] == 0) {
        l = max(j - i, l);
        while (nums[i] != 0) {
          i++;
        }
        i++;
        c -= 1;
      } else {
        c += 1 - nums[j];
        j++;
      }
    }
    l = max(j - i, l);
    return l;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
