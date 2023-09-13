#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
  int t, n, m;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &n, &m);
    printf("%d\n", (int)(ceil(n / 3) * ceil(m / 3)));
  }
  return 0;
}
