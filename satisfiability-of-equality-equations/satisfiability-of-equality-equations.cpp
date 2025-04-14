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

class UF {
private:
  vi rank, parent, sz;
  int n;

public:
  UF(int n) : n(n) {
    rank.assign(n, 1);
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    sz.assign(n, 1);
  }

  int getParent(int i) {
    while (parent[i] != i)
      i = parent[i];
    return i;
  }

  bool sameSet(int i, int j) { return getParent(i) == getParent(j); }

  void setUnion(int i, int j) {
    i = getParent(i), j = getParent(j);
    if (i == j)
      return;

    if (rank[i] < rank[j])
      swap(i, j);
    if (rank[i] == rank[j])
      rank[i]++;

    parent[j] = i;
    sz[i] += sz[j];
  }
};

class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    vector<int> eq, neq;
    int numVars = 0;
    unordered_map<char, int> mp;

    int n = equations.size();
    for (int i = 0; i < n; i++) {
      string &e = equations[i];
      if (e[1] == '=') {
        eq.push_back(i);
      } else {
        neq.push_back(i);
      }

      if (mp.count(e[0]) == 0) {
        mp[e[0]] = numVars++;
      }
      if (mp.count(e[3]) == 0) {
        mp[e[3]] = numVars++;
      }
    }

    UF uf(numVars);
    for (int i : eq) {
      string &e = equations[i];

      char x = e[0], y = e[3];
      int xi = mp[x], yi = mp[y];
      uf.setUnion(xi, yi);
    }

    for (int i : neq) {
      string &e = equations[i];

      char x = e[0], y = e[3];
      int xi = mp[x], yi = mp[y];
      if (uf.sameSet(xi, yi))
        return false;
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
