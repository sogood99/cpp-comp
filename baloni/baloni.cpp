#include <bits/stdc++.h>

#define H 10000001

using namespace std;

int main() {
  int n;
  cin >> n;

  int *hist = new int[H];
  memset(hist, 0, sizeof(int) * H);

  int t, count = 0;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (hist[t] > 0) {
      hist[t]--;
    } else {
      count++;
    }
    if (t > 1) {
      hist[t - 1]++;
    }
  }
  cout << count << endl;
  return 0;
}
