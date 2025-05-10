#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <queue>

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
  map<TreeNode *, int> dist;
  map<TreeNode *, TreeNode *> parent;

  int getDist(TreeNode *n) {
    if (dist.count(n) != 0) {
      return dist[n];
    }

    int &d = dist[n];
    d = getDist(parent[n]) + 1;
    return d;
  }

  int constructDist(TreeNode *n, TreeNode *target) {
    if (n == target) {
      dist[n] = 0;
      return 0;
    }

    if (!n) {
      return -1;
    }

    int d = constructDist(n->left, target);
    d = max(d, constructDist(n->right, target));
    if (d != -1) {
      d++;
      dist[n] = d;
    }
    return d;
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    constructDist(root, target);

    queue<TreeNode *> q;
    q.push(root);

    vector<int> res;

    while (!q.empty()) {
      TreeNode *n = q.front();
      q.pop();

      if (dist.count(n) == 0) {
        dist[n] = getDist(n);
      }
      if (dist[n] == k) {
        res.push_back(n->val);
      }

      if (n->left) {
        q.push(n->left);
        parent[n->left] = n;
      }
      if (n->right) {
        q.push(n->right);
        parent[n->right] = n;
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
