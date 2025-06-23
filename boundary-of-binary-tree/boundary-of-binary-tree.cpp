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
public:
  vector<int> boundaryOfBinaryTree(TreeNode *root) {
    vector<int> res;

    res.push_back(root->val);

    if (root->left) {
      TreeNode *node = root->left;

      while (node->left || node->right) {
        res.push_back(node->val);
        if (node->left) {
          node = node->left;
        } else {
          node = node->right;
        }
      }
    }
    vector<TreeNode *> stk = {root};
    while (!stk.empty()) {
      TreeNode *n = stk.back();
      stk.pop_back();

      if (n->left == nullptr && n->right == nullptr && n != root) {
        res.push_back(n->val);
      }

      if (n->right)
        stk.push_back(n->right);
      if (n->left)
        stk.push_back(n->left);
    }

    vector<int> right_bdr;

    if (root->right) {
      TreeNode *node = root->right;

      while (node->right || node->left) {
        right_bdr.push_back(node->val);
        if (node->right) {
          node = node->right;
        } else {
          node = node->left;
        }
      }
    }
    reverse(right_bdr.begin(), right_bdr.end());

    res.insert(res.end(), right_bdr.begin(), right_bdr.end());
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
