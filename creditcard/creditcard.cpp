#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void pay_time(double r, double B, double M) {
  int iter = 1;
  ll r_l = r * 1000000, B_l = B * 1000000, M_l = M * 1000000;
  while (iter < 1200) {
    ll interest = B_l * r_l / 100 / 1000000;
    ll interest_small = interest % 10000;
    if (interest_small >= 5000) {
      interest = interest / 10000 + 1;
    } else {
      interest = interest / 10000;
    }
    interest *= 10000;

    ll n_B = B_l + interest - M_l;

    // cout << interest << " " << B_l << endl;
    if (n_B >= B_l) {
      cout << "impossible" << endl;
      return;
    }

    B_l = n_B;

    if (B_l <= 0) {
      cout << iter << endl;
      return;
    }
    iter++;
  }
  cout << "impossible" << endl;
}

int main() {
  int T;
  cin >> T;

  double r, B, M;
  for (int i = 0; i < T; i++) {
    cin >> r >> B >> M;
    pay_time(r, B, M);
  }

  return 0;
}
