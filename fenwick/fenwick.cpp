#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;

const int N = 5000010;

ll ft[N];

void init_ft() {
  for (int i = 0; i < N; i++) {
    ft[i] = 0;
  }
}
ll rsq(int j) {
  ll sum = 0;
  for (; j; j -= LSOne(j))
    sum += ft[j];

  return sum;
}
ll rsq(int i, int j) { return rsq(j) - rsq(i); }
void update(int i, int v) {
  for (; i < N; i += LSOne(i))
    ft[i] += v;
}

int main() {

  init_ft();
  int N, Q;
  scanf("%d %d\n", &N, &Q);

  char c;
  int i, v;
  while (Q--) {
    scanf("%c %d", &c, &i);
    if (c == '+') {
      scanf("%d", &v);
      update(i + 1, v);
    } else if (c == '?') {
      printf("%lld\n", rsq(i));
    }
    scanf("\n");
  }

  return 0;
}
