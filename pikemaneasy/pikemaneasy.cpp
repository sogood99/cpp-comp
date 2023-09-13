#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ll N, T;
  cin >> N >> T;
  vector<ll> t(N, 0);

  ll A, B, C;
  cin >> A >> B >> C >> t[0];

  for (ll i = 1; i < N; i++) {
    t[i] = (A * t[i - 1] + B) % C + 1;
  }
  sort(t.begin(), t.end());

  ll solved = 0, penalty = 0, time = 0;
  while (solved < N && t[solved] + time < T) {
    time += t[solved];
    penalty = (penalty + time) % 1000000007;
    solved++;
  }
  cout << solved << " " << penalty << endl;
  return 0;
}
