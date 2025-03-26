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
  bool isVowel(char c) {
    return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' ||
           c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
  }
  string reverseVowels(string s) {

    vector<int> idx;
    vector<char> vowels;

    for (int i = 0; i < s.length(); i++) {
      if (isVowel(s[i])) {
        idx.push_back(i);
        vowels.push_back(s[i]);
      }
    }

    int vs = vowels.size();
    for (int i = 0; i < vs; i++) {
      s[idx[vs - i - 1]] = vowels[i];
    }
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
