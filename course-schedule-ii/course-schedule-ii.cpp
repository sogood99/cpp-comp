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
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses);

    for (vector<int> &e : prerequisites) {
      int v = e[0], u = e[1];
      adj[u].push_back(v);

      indegree[v]++;
    }

    vector<int> order;
    queue<int> q;

    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      order.push_back(u);

      for (int v : adj[u]) {
        indegree[v]--;
        if (indegree[v] == 0)
          q.push(v);
        else if (indegree[v] < 0)
          return {};
      }
    }

    return order.size() == numCourses ? order : vector<int>{};
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
