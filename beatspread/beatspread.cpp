#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int S, D; // a+b, a-b, where a >= b;
    cin >> S >> D;
    int a = (S + D) / 2;
    int b = (S - D) / 2;

    if ((a + b) == S && abs(a - b) == D && a >= 0 && b >= 0) {
      cout << max(a, b) << " " << min(a, b) << endl;
    } else {
      cout << "impossible" << endl;
    }
  }
  return 0;
}
