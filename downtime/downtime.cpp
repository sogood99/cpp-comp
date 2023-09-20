#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#define N 102000

using namespace std;

int main() {
  int n, k;
  int process[N];
  memset(process, 0, sizeof(process));

  int t;
  int max_num = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> t;
    for (int j = t; j < t + 1000; j++) {
      process[j]++;
      max_num = max((int)ceil(process[t] / (double)k), max_num);
    }
  }
  cout << max_num << endl;

  return 0;
}
