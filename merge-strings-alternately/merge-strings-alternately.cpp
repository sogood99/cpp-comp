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
  string mergeAlternately(string word1, string word2) {
    size_t i = 0, j = 0, k = 0;
    string s(word1.length() + word2.length(), 0);
    while (i < word1.length() && j < word2.length()) {
      s[k++] = word1[i];
      s[k++] = word2[j];
      i++;
      j++;
    }

    while (i < word1.length()) {
      s[k++] = word1[i++];
    }
    while (j < word2.length()) {
      s[k++] = word2[j++];
    }
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
