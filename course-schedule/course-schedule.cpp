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

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // find toposort
    vector<int> indegree(numCourses), order;
    vector<vector<int>> adj(numCourses);
    queue<int> q;
    for (int i = 0; i < prerequisites.size(); i++) {
      int u = prerequisites[i][1], v = prerequisites[i][0];
      adj[u].push_back(v);
      indegree[v]++;
    }
    for (int i = 0; i < numCourses; i++) {
      if (!indegree[i])
        q.push(i);
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      order.push_back(u);

      for (int v : adj[u]) {
        if (--indegree[v] == 0) {
          q.push(v);
        }
      }
    }

    return order.size() == numCourses;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
