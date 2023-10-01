#include <algorithm>
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

class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    if (points.size() == 1) {
      return 1;
    }

    int N = points.size();
    int maxCount = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        int count = 0;
        const vi p1 = points[i], p2 = points[j];
        const int dx = p1[0] - p2[0], dy = p1[1] - p2[1];
        const int x0 = p1[0], y0 = p1[1];

        for (const vi &p : points) {
          const int x = p[0], y = p[1];
          const int d = dx * y - dy * x + dy * x0 - dx * y0;
          if (d == 0) {
            count++;
          }
        }

        maxCount = max(count, maxCount);
      }
    }
    return maxCount;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> v = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

  cout << Solution().maxPoints(v) << endl;

  return 0;
}
