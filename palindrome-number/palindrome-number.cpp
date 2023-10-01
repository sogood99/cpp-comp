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
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    int r = 0, t = x;
    while (t != 0) {
      r *= 10;
      r += t % 10;
      t /= 10;
    }

    return (x == r) ? true : false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << Solution().isPalindrome(12321);

  return 0;
}
