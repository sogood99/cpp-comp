#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, K;

  cin >> N >> M >> K;

  vd p(N), h(M + K);

  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < K; i++) {
    double t = 0;
    cin >> t;
    h[i + M] = t / sqrt(2.0);
    // cout << t / sqrt(2.0) << endl;
  }

  sort(p.begin(), p.end());
  sort(h.begin(), h.end());

  int i = 0, j = 0, cnt = 0;
  while ((i < N) && (j < M + K)) {
    while (i < N && p[i] <= h[j])
      i++;
    if (i == N)
      break;
    cnt++;
    i++, j++;
  }

  cout << cnt << endl;

  return 0;
}
