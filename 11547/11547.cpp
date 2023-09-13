#include <bits/stdc++.h>
#include <cstdio>

typedef long long ll;

using namespace std;

int main() {
  int t, n;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    double res = (double)n;
    res *= 567;
    res /= 9;
    res += 7492;
    res *= 235;
    res /= 47;
    res -= 498;
    int k = 1;
    if (res < 0) {
      k = -1;
    }
    printf("%lld\n", (((ll)(res / 10)) % 10) * k);
  }
  return 0;
}
