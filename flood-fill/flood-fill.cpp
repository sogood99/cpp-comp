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

class Solution {
private:
  bool inImage(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int m = image.size(), n = image[0].size();

    queue<ii> q;
    q.push({sr, sc});

    int original_color = image[sr][sc];
    if (original_color == color) {
      return image;
    }

    vector<ii> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      if (!inImage(i, j, m, n) || image[i][j] != original_color) {
        continue;
      }
      image[i][j] = color;

      for (auto [dx, dy] : d) {
        q.push({i + dx, j + dy});
      }
    }

    return image;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
