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

ll A[2010], n;

ll memo_lis[2010], memo_lds[2010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  ll mv = 1;

  for (int i = n - 1; i >= 0; i--) {
    memo_lis[i] = memo_lds[i] = 1;
    for (int j = i + 1; j < n; j++) {
      if (A[i] < A[j]) {
        memo_lis[i] = max(memo_lis[j] + 1, memo_lis[i]);
      } else if (A[i] > A[j]) {
        memo_lds[i] = max(memo_lds[j] + 1, memo_lds[i]);
      }
    }
    // cout << memo_lis[i] << memo_lds[i] << endl;
    mv = max(memo_lis[i] + memo_lds[i] - 1, mv);
  }

  cout << mv << endl;
  return 0;
}
