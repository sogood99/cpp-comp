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
  int getParent(int a, vector<int> &parent) {
    while (parent[a] != a)
      a = parent[a];
    return a;
  }

public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<int> parent(26);
    iota(parent.begin(), parent.end(), 0);

    int n = s1.size();

    for (int i = 0; i < n; i++) {
      int a = s1[i] - 'a', b = s2[i] - 'a';
      int pa = getParent(a, parent), pb = getParent(b, parent);

      if (pa != pb) {
        if (pa > pb) {
          swap(a, b);
          swap(pa, pb);
        }
        parent[pb] = parent[pa];
      }
    }

    int s = baseStr.size();

    for (int i = 0; i < s; i++) {
      char c = getParent(baseStr[i] - 'a', parent) + 'a';
      baseStr[i] = c;
    }

    return baseStr;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
