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
  unordered_map<TreeNode *, int> maxSum;

  int dfs(TreeNode *node) {
    if (!node) {
      return 0;
    }

    if (maxSum.count(node)) {
      return maxSum[node];
    }

    int &val = maxSum[node];
    val = node->val;

    int l = dfs(node->left) + node->val;
    val = max(l, val);
    int r = dfs(node->right) + node->val;
    val = max(r, val);

    return val;
  }

public:
  int maxPathSum(TreeNode *root) {
    if (!root)
      return 0;

    queue<TreeNode *> q;
    q.push(root);
    int mx = INT_MIN;
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      int cv = max(dfs(node->left), 0) + node->val + max(dfs(node->right), 0);
      mx = max(cv, mx);
      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
    return mx;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
