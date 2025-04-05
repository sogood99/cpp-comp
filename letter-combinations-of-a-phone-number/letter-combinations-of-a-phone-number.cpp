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

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (!digits.length()) {
      return vector<string>();
    }
    vector<string> res = {""};
    map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                           {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                           {'8', "tuv"}, {'9', "wxyz"}};

    int n = digits.length();
    for (int i = 0; i < n; i++) {
      char c = digits[i];

      int k = res.size();
      vector<string> nres;
      while (k > 0) {
        string s = res.back();
        res.pop_back();
        for (char ca : m[c]) {
          nres.push_back(s + ca);
        }
        k--;
      }
      swap(nres, res);
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
