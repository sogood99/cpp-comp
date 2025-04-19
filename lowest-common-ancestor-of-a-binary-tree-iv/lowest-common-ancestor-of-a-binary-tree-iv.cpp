#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <unordered_set>

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  void dfs(TreeNode *node, const unordered_set<TreeNode *> &nodes,
           vector<pair<TreeNode *, int>> &v, int &i, int &j, int d) {

    if (nodes.count(node)) {
      if (i == -1) {
        i = v.size();
        j = v.size();
      } else {
        j = v.size();
      }
    }

    v.emplace_back(node, d);
    if (node->left) {
      dfs(node->left, nodes, v, i, j, d + 1);
      v.emplace_back(node, d);
    }
    if (node->right) {
      dfs(node->right, nodes, v, i, j, d + 1);
      v.emplace_back(node, d);
    }
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes) {
    vector<pair<TreeNode *, int>> traversal;
    unordered_set<TreeNode *> nds(nodes.begin(), nodes.end());

    int i = -1, j = -1;
    dfs(root, nds, traversal, i, j, 0);

    int min_d = INT_MAX;
    TreeNode *anc = nullptr;
    for (int k = i; k <= j; k++) {
      auto [n, d] = traversal[k];
      if (d < min_d) {
        min_d = d;
        anc = n;
      }
    }

    return anc;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
