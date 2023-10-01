#include <bits/stdc++.h>
#include <vector>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

// Definition for a binary tree node.
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
  int getMinimumDifference(TreeNode *root) {
    if (root == nullptr) {
      return INF;
    }
    TreeNode *n1 = root->left, *n2 = root->right;
    int a, b;
    if (n1 == nullptr) {
      a = -INF;
    } else {
      while (n1->right != nullptr)
        n1 = n1->right;
      a = n1->val;
    }
    if (n2 == nullptr) {
      b = INF;
    } else {
      while (n2->left != nullptr)
        n2 = n2->left;
      b = n2->val;
    }

    int d1 = min(b - root->val, root->val - a);
    int d2 = min(getMinimumDifference(root->left),
                 getMinimumDifference(root->right));
    return min(d1, d2);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
