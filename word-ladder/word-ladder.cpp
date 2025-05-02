#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <iterator>

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

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    // build graph
    int n = wordList.size(), sz = beginWord.size(), endIdx;

    for (int i = 1; i <= n; i++) {
      if (wordList[i - 1] == endWord) {
        endIdx = i;
        break;
      }
    }

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        int diff = 0;
        string &a = i == 0 ? beginWord : wordList[i - 1];
        string &b = wordList[j - 1];
        for (int k = 0; k < sz; k++) {
          if (a[k] != b[k])
            diff++;

          if (diff > 1)
            break;
        }

        if (diff <= 1) {
          adj[i].push_back(j);
          if (i != 0)
            adj[j].push_back(i);
        }
      }
    }

    vector<int> q;
    vector<int> visited(n + 1);
    q.push_back(0);
    visited[0] = 1;
    int d = 0;

    while (!q.empty()) {
      vector<int> new_q;
      for (int u : q) {
        if (u == endIdx)
          return d;
        for (int v : adj[u]) {
          if (!visited[v]) {
            visited[v] = 1;
            new_q.push_back(v);
          }
        }
      }

      swap(new_q, q);

      d++;
    }

    return 0;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
