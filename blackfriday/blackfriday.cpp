#include <algorithm>
#include <bits/stdc++.h>

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  int arr[110];
  fill_n(arr, 0, -1);

  int t;
  for (int i = 0; i < N; i++) {
    cin >> t;
    arr[i] = t;
  }

  int gts_v = -1, gts_i = -1;
  for (int i = 0; i < N; i++) {
    if (arr[i] < gts_v) {
      continue;
    }

    bool gts = true;
    for (int j = 0; j < N; j++) {
      if (j != i && arr[j] == arr[i]) {
        gts = false;
        break;
      }
    }
    if (gts) {
      gts_v = arr[i];
      gts_i = i;
    }
  }

  if (gts_i != -1) {
    cout << gts_i + 1 << endl;
  } else {
    cout << "none" << endl;
  }

  return 0;
}
