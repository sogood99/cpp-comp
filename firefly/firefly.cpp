#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>

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
int N, H;
vi v0, v1;

int min_obs = INF, cnt = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> H;

  int t;
  for (int i = 0; i < N; i++) {
    cin >> t;
    if (i % 2) {
      v1.push_back(H - t);
    } else {
      v0.push_back(t);
    }
  }

  sort(v0.begin(), v0.end());
  sort(v1.begin(), v1.end());

  for (int h = 1; h <= H; h++) {
    auto it1 = lower_bound(v0.begin(), v0.end(), h),
         it2 = lower_bound(v1.begin(), v1.end(), h);

    int d1 = distance(it1, v0.end()), d2 = distance(v1.begin(), it2);
    int d = d1 + d2;
    // cout << "+++++++++++++++" << endl;
    // cout << *it1 << " " << *it2 << endl;
    // cout << d1 << " " << d2 << endl;
    if (d < min_obs) {
      min_obs = d;
      cnt = 1;
    } else if (d == min_obs) {
      cnt++;
    }
  }

  cout << min_obs << " " << cnt << endl;

  return 0;
}
