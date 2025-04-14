#include <algorithm>
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <iterator>

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
  vector<int> rank, parent;
  unordered_map<string, int> id;
  int n;

public:
  UF(int n) {
    rank.assign(n, 1);
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    this->n = n;
  }

  void insert(int g, vector<string> &emails) {
    for (int i = 1; i < emails.size(); i++) {
      if (id.count(emails[i]) != 0) {
        unionSet(g, id[emails[i]]);
      } else {
        id[emails[i]] = g;
      }
    }
  }

  int totalSize() { return n; }

  int getParent(int i) {
    while (parent[i] != i)
      i = parent[i];
    return i;
  }

  void unionSet(int i, int j) {
    i = getParent(i), j = getParent(j);
    if (i == j) {
      // already same set
      return;
    }
    if (rank[i] < rank[j]) {
      swap(i, j);
    }

    if (rank[j] == rank[i]) {
      rank[i]++;
    }
    parent[j] = i;
  }
};

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int accNum = accounts.size();
    UF uf(accNum);
    for (int i = 0; i < accNum; i++) {
      uf.insert(i, accounts[i]);
    }

    unordered_map<int, set<string>> mp;

    for (int i = 0; i < accNum; i++) {
      int g = uf.getParent(i);
      for (int j = 1; j < accounts[i].size(); j++) {
        mp[g].insert(accounts[i][j]);
      }
    }

    vector<vector<string>> res;
    for (auto &p : mp) {
      int g = p.first;
      vector<string> curr;
      curr.push_back(accounts[g][0]); // name
      curr.insert(curr.end(), p.second.begin(), p.second.end());
      res.push_back(curr);
    }
    return res;
  };
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
