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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

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
class Solution {
public:
  bool checkEqualTree(TreeNode *root) { return isEqual(root, 0); }

  bool isEqual(TreeNode *root, int topSum) {
    int ls = sum(root->left), rs = sum(root->right);

    if (root->right && ls + root->val + topSum == rs)
      return true;

    if (root->left && ls == root->val + topSum + rs)
      return true;

    if (root->left && isEqual(root->left, topSum + root->val + rs))
      return true;

    if (root->right && isEqual(root->right, topSum + root->val + ls))
      return true;

    return false;
  }

  int sum(TreeNode *node) {
    if (!node)
      return 0;
    queue<TreeNode *> q;
    q.push(node);

    int s = 0;

    while (!q.empty()) {
      auto n = q.front();
      q.pop();

      s += n->val;
      if (n->left)
        q.push(n->left);
      if (n->right)
        q.push(n->right);
    }
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
