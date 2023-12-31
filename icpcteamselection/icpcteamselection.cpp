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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int arr[310];

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    for (int i = 0; i < 3 * N; i++) {
      cin >> arr[i];
    }

    sort(arr, arr + 3 * N);

    int S = 0;
    int k = 3 * N - 1;

    for (int i = 0; i < N; i++) {
      k--;
      S += arr[k];
      k--;
    }

    cout << S << endl;
  }

  return 0;
}
