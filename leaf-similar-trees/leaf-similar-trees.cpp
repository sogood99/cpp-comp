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
const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18;  // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  bool isLeaf(TreeNode* n) {
    return n->left == nullptr && n->right == nullptr;
  }

  int nextLeaf(vector<TreeNode*>& stk) {
    int v1;
    while (!isLeaf(stk.back())) {
      TreeNode* n1 = stk.back();
      stk.pop_back();
      if (n1->right != nullptr)
        stk.push_back(n1->right);
      if (n1->left != nullptr)
        stk.push_back(n1->left);
    }
    v1 = stk.back()->val;
    stk.pop_back();
    return v1;
  }

  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<TreeNode*> s1, s2;
    s1.push_back(root1);
    s2.push_back(root2);

    while (s1.size() > 0 && s2.size() > 0) {
      if (nextLeaf(s1) != nextLeaf(s2)) {
        return false;
      }
    }

    return s1.size() == 0 && s2.size() == 0;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
