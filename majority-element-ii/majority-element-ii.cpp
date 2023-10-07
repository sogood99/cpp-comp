#include <bits/stdc++.h>
#include <vector>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int b = -1, c = -1, cnt_b = 0, cnt_c = 0;

    for (int a : nums) {
      if (a == b) {
        cnt_b++;
      } else if (a == c) {
        cnt_c++;
      } else if (cnt_b == 0) {
        b = a;
        cnt_b = 0;
      } else if (cnt_c == 0) {
        c = a;
        cnt_c = 0;
      } else {
        cnt_c--;
        cnt_b--;
      }
    }

    cnt_c = cnt_b = 0;
    for (int a : nums) {
      if (a == b) {
        cnt_b++;
      } else if (a == c) {
        cnt_c++;
      }
    }

    vector<int> ret;
    if (cnt_c > nums.size() / 3) {
      ret.push_back(c);
    }
    if (cnt_b > nums.size() / 3) {
      ret.push_back(b);
    }
    return ret;
  }
};

// boye more
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
