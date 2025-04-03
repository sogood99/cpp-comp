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
  int pathSumMemo(TreeNode* n, long long target, vector<long long>& pre) {
    if (n == nullptr) {
      return 0;
    }
    long long ps = pre.back() + n->val, cnt = 0;

    for (long long v : pre) {
      if (ps - v == target) {
        cnt++;
      }
    }

    pre.push_back(ps);
    cnt += pathSumMemo(n->left, target, pre);
    cnt += pathSumMemo(n->right, target, pre);
    pre.pop_back();

    return cnt;
  }

  int pathSum(TreeNode* root, int targetSum) {
    vector<long long> v;
    v.push_back(0);

    return pathSumMemo(root, targetSum, v);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
