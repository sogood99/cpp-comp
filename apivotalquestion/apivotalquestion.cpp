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

  set<int, greater<int>> L;
  set<int> U;

  int n;
  cin >> n;

  vi A(n + 10);

  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    U.insert(t);
    A[i] = t;
  }

  int cnt = 0;
  vi res;
  for (int i = 0; i < n; i++) {
    U.erase(A[i]);

    if ((L.empty() || A[i] > *L.begin()) && (U.empty() || A[i] < *U.begin())) {
      cnt++;
      if (res.size() < 100)
        res.push_back(A[i]);
    }

    L.insert(A[i]);
  }

  cout << cnt;
  for (const int k : res) {
    cout << " " << k;
  }
  cout << endl;

  return 0;
}
