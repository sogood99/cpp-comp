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
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    root = new TrieNode();
    vector<TrieNode *> q;

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
      q.push_back(node);
    }

    // dfs

    unordered_set<int> r;
    vector<string> res;

    while (!q.empty()) {
      auto node = q.back();
      q.pop_back();

      for (auto &w : words) {
        auto n = node;
        for (auto c : w) {
          n = n->children[c];
          if (n == nullptr) {
            break;
          }
        }

        if (n != nullptr) {
          if (n->word != -1) {
            if (r.count(n->word) == 0) {
              r.insert(n->word);
              res.push_back(words[n->word]);
            }
          } else {
            q.push_back(n);
          }
        }
      }
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
