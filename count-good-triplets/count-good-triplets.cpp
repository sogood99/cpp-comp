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
  int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    int count = 0, n = arr.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (abs(arr[i] - arr[j]) > a)
          continue;
        for (int k = j + 1; k < n; k++) {
          if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
            count++;
          }
        }
      }
    }

    return count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
