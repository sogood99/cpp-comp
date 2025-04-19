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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  void dfs(TreeNode *root, vector<pair<TreeNode *, int>> &v, int &i, int &j,
           int d, TreeNode *p, TreeNode *q) {
    v.emplace_back(root, d);
    if (root == p && i == -1) {
      i = v.size() - 1;
    } else if (root == q && j == -1) {
      j = v.size() - 1;
    }
    if (root->left) {
      dfs(root->left, v, i, j, d + 1, p, q);
      v.emplace_back(root, d);
    }
    if (root->right) {
      dfs(root->right, v, i, j, d + 1, p, q);
      v.emplace_back(root, d);
    }
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<pair<TreeNode *, int>> v;
    int i = -1, j = -1;
    dfs(root, v, i, j, 0, p, q);

    int min_depth = INT_MAX;
    TreeNode *anc = nullptr;

    for (int k = min(i, j); k <= max(i, j); k++) {
      auto [n, d] = v[k];
      if (min_depth > d) {
        min_depth = d;
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
