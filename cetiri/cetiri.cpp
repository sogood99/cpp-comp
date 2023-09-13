#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
  int s[3];
  for (int i = 0; i < 3; i++) {
    scanf("%d", s + i);
  }
  sort(s, s + 3);
  int l = s[1] - s[0], r = s[2] - s[1];
  if (l == r) {
    printf("%d\n", s[2] + l);
  } else if (l < r) {
    printf("%d\n", s[1] + l);
  } else {
    printf("%d\n", s[0] + r);
  }

  return 0;
}
