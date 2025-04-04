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

struct TrieNode {
  TrieNode *children[26] = {nullptr};
  bool isEnd = false;
};

void insert(TrieNode *root, string s) {
  TrieNode *n = root;
  for (char c : s) {
    if (n->children[c - 'a'] == nullptr) {
      TrieNode *nn = new TrieNode;
      n->children[c - 'a'] = nn;
    }
    n = n->children[c - 'a'];
  }
  n->isEnd = true;
}

void dfs(TrieNode *root, string prefix, vector<string> &ret) {
  if (ret.size() == 3) {
    return;
  }
  if (root->isEnd) {
    ret.push_back(prefix);
  }

  for (char c = 'a'; c <= 'z'; c++) {
    TrieNode *nn = root->children[c - 'a'];
    if (nn) {
      dfs(nn, prefix + c, ret);
    }
  }
}

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    TrieNode *root = new TrieNode;

    vector<vector<string>> res(searchWord.size());

    string pre;

    for (string &s : products) {
      insert(root, s);
    }

    for (int i = 0; i < searchWord.length(); i++) {
      char c = searchWord[i];
      pre += c;
      root = root->children[c - 'a'];
      if (!root) {
        break;
      }

      dfs(root, pre, res[i]);
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
