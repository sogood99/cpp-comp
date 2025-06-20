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

class Trie {
public:
  unordered_map<char, Trie *> children;
  string word;
};

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    int m = board.size(), n = board[0].size();

    Trie *root = new Trie();

    for (string &w : words) {
      Trie *node = root;

      for (char c : w) {
        if (node->children.count(c) == 0) {
          Trie *next = new Trie();

          node->children[c] = next;
          node = next;
        } else {
          node = node->children[c];
        }
      }

      node->word = w;
    }

    unordered_set<string> res;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        backtrack(i, j, root, board, res);
      }
    }

    vector<string> r;
    for (string s : res) {
      r.push_back(s);
    }

    return r;
  }

  void backtrack(int i, int j, Trie *node, vector<vector<char>> &board,
                 unordered_set<string> &res) {
    int m = board.size(), n = board[0].size();

    char c = board[i][j];

    if (c == '#' || node->children.count(c) == 0) {
      return;
    }

    static vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    board[i][j] = '#';
    node = node->children[c];

    for (auto &p : d) {
      int x = i + p.first, y = j + p.second;

      if (x < 0 || x >= m || y < 0 || y >= n)
        continue;

      backtrack(x, y, node, board, res);
    }

    if (!node->word.empty())
      res.insert(node->word);

    board[i][j] = c;
    return;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
