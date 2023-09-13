#include <bits/stdc++.h>
#include <cmath>

typedef long long ll;

using namespace std;

int main() {
  int count;
  ll n;
  scanf("%d", &count);
  while (count > 0) {

    scanf("%lld", &n);
    printf("%lld\n", (ll)floor((-1 + sqrt(8 * (double)n + 1)) / 2));
    count--;
  }

  return 0;
}
