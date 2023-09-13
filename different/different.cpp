#include <bits/stdc++.h>
#include <cstdio>

typedef long long ll;

using namespace std;

int main() {
  ll m, n;
  while (scanf("%lld %lld", &m, &n) != EOF) {
    ll res = m - n;
    if (res < 0) {
      res *= -1;
    }
    printf("%lld\n", res);
  }
  return 0;
}
