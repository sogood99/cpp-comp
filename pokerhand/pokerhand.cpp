#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int count[50] = {0};
  memset(count, 0, sizeof(count));

  char s[5];

  while (scanf("%s", s) != EOF) {
    if (s[0] == 'A') {
      count[0]++;
    } else if (s[0] >= '2' && s[0] <= '9') {
      count[s[0] - '2' + 1]++;
    } else {
      count[s[0] - 'J' + 9]++;
    }
  }
  printf("%d\n", *max_element(count, count + 50));
  return 0;
}
