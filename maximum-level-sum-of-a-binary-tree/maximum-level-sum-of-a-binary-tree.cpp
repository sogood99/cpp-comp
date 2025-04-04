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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int maxLevelSum(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    vector<TreeNode*> q;
    q.push_back(root);
    int l = 1, ms = INT_MIN, ml = 0;

    while (!q.empty()) {
      vector<TreeNode*> nq;
      int s = 0;

      for (auto n : q) {
        s += n->val;
        if (n->left != nullptr) {
          nq.push_back(n->left);
        }
        if (n->right != nullptr) {
          nq.push_back(n->right);
        }
      }

      if (s > ms) {
        ml = l;
        ms = s;
      }
      swap(q, nq);

      l++;
    }

    return ml;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
