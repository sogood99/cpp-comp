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
  bool isVowel(char a) {
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
  }
  int maxVowels(string s, int k) {
    int mv = 0, cv = 0;

    for (int i = 0; i < k - 1; i++) {
      cv += isVowel(s[i]);
    }
    cout << cv << endl;
    cout << s.length() - k << endl;

    for (int i = 0; i <= s.length() - k; i++) {
      if (i > 0) {
        cv -= isVowel(s[i - 1]);
      }
      cv += isVowel(s[i + k - 1]);
      mv = max(mv, cv);
      cout << cv << endl;
    }
    return mv;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> v = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

  cout << Solution().maxPoints(v) << endl;

  return 0;
}
