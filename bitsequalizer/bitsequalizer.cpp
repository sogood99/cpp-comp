#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int moves_count(char S[200], char T[200]) {
  int a, b, c, d;
  a = b = c = d = 0;
  for (int j = 0; j < 105; j++) {
    if (T[j] == 0) {
      break;
    } else if (S[j] != T[j]) {
      if (S[j] == '0' && T[j] == '1') {
        a++;
      } else if (S[j] == '1' && T[j] == '0') {
        b++;
      } else if (S[j] == '?' && T[j] == '0') {
        c++;
      } else if (S[j] == '?' && T[j] == '1') {
        d++;
      }
    }
  }

  if (b > a + d) {
    return -1;
  } else {
    int moves = 0;

    int count_a_b = min(a, b);
    moves += count_a_b;
    a -= count_a_b;
    b -= count_a_b;

    moves += a;
    moves += b;
    moves += c;
    moves += d;
    return moves;
  }
}

int main() {
  int t;
  int a, b, c, d;
  a = b = c = d = 0;
  char S[200], T[200];
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%s %s", S, T);
    int res = moves_count(S, T);
    printf("Case %d: %d\n", i + 1, res);
  }

  return 0;
}
