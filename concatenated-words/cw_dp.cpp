#include <bits/extc++.h>
#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

struct TrieNode {
  unordered_map<char, TrieNode *> children;
  int word = -1;
};

class Solution {
private:
  TrieNode *root;

public:
  bool canForm(string &word, int i, vector<int> &dp) {
    if (i == word.size())
      return true;

    if (dp[i] != -1)
      return dp[i];

    TrieNode *n = root;

    for (int j = i; j < word.size(); j++) {
      char c = word[j];
      if (!n->children.count(c))
        break;
      n = n->children[c];
      if (n->word != -1 && canForm(word, j + 1, dp)) {
        dp[i] = 1;
        return dp[i];
      }
    }

    dp[i] = 0;
    return dp[i];
  }

  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    root = new TrieNode();

    vector<TrieNode *> nodes;

    for (int i = 0; i < words.size(); i++) {
      string &w = words[i];
      auto node = root;
      for (char c : w) {
        if (node->children.count(c) == 0) {
          node->children[c] = new TrieNode();
        }
        node = node->children[c];
      }

      node->word = i;
      nodes.push_back(node);
    }

    vector<string> res;

    for (int i = 0; i < words.size(); i++) {
      string &w = words[i];
      TrieNode *n = nodes[i];

      n->word = -1;
      vector<int> dp(w.size(), -1);
      if (canForm(w, 0, dp)) {
        res.push_back(w);
      }
      n->word = i;
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
