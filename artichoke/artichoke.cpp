#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>

#define N 1000002
using namespace std;

int main() {
  int n;
  double price_current, price_max;

  double p, a, b, c, d;
  double largest = 0;
  scanf("%lf%lf%lf%lf%lf%d", &p, &a, &b, &c, &d, &n);
  price_max = p * (sin(a + b) + cos(c + d) + 2);
  largest = 0;

  for (int i = 1; i <= n; i++) {
    price_current = p * (sin(a * i + b) + cos(c * i + d) + 2);
    largest = max(largest, price_max - price_current);
    price_max = max(price_max, price_current);
  }

  printf("%lf\n", largest);

  return 0;
}
