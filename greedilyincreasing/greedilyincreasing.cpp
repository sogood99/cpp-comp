#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, count = 0;
  cin >> n;
  int *memo = new int[n];
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (count == 0 || memo[count - 1] < t) {
      memo[count] = t;
      count++;
    }
  }
  cout << count << endl;
  for (int i = 0; i < count; i++) {
    cout << memo[i];
    if (i != count - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }

  return 0;
}
