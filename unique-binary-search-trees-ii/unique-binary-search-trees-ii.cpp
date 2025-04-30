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
private:
  void dfs_add(TreeNode *root, int add) {
    if (!root) {
      return;
    }
    root->val += add;

    dfs_add(root->left, add);
    dfs_add(root->right, add);
  }

  TreeNode *copy(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    TreeNode *new_root = new TreeNode(root->val);
    new_root->left = copy(root->left);
    new_root->right = copy(root->right);
    return new_root;
  }

public:
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0) {
      return {nullptr};
    } else if (n == 1) {
      return {new TreeNode(1)};
    }

    vector<TreeNode *> res;

    for (int i = 1; i <= n; i++) {
      // split by i
      vector<TreeNode *> left = generateTrees(i - 1);
      vector<TreeNode *> right = generateTrees(n - i);
      for (auto *r : right) {
        dfs_add(r, i);
      }

      for (auto *l : left) {
        for (auto *r : right) {
          TreeNode *nl = copy(l), *nr = copy(r);
          TreeNode *mid = new TreeNode(i);
          mid->left = nl;
          mid->right = nr;
          res.push_back(mid);
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
