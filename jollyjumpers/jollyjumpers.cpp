#include <bits/stdc++.h>
#include <cstring>

#define N 300000

using namespace std;

bool check_jolly(int n) {
  bool b[N];
  memset(b, false, sizeof(b));

  int *s = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n - 1; i++) {
    b[abs(s[i + 1] - s[i])] = true;
  }

  for (int i = 1; i <= n - 1; i++) {
    if (!b[i]) {
      return false;
    }
  }

  return true;
}

int main() {

  int n;
  while (cin >> n) {
    bool b = check_jolly(n);
    if (b) {
      cout << "Jolly" << endl;
    } else {
      cout << "Not jolly" << endl;
    }
  }

  return 0;
}
