#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

#define MAXSIZE 62

typedef long long ll;
typedef pair<int, int> ii;

int translate(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'a' && c <= 'z') {
    return c - 'a' + 10;
  } else if (c >= 'A' && c <= 'Z') {
    return c - 'A' + 36;
  }
  return 0;
}

bool run() {
  char s[110][110];
  int N = 0, M = 0;
  ii loc[MAXSIZE + 2];
  int count = 0;

  char *c;
  c = fgets(s[0], sizeof(s[0]), stdin);
  if (c == NULL) {
    return false;
  }

  M = strlen(s[0]) - 1;

  for (int j = 0; j < M; j++) {
    if (s[N][j] != '.') {
      char c = s[N][j];
      int idx = translate(c);
      loc[idx] = ii(N, j);
      count++;
      // cout << "FOUND " << idx << " " << N << " " << j << endl;
    }
  }

  N++;

  while (fgets(s[N], sizeof(s[N]), stdin) != NULL && s[N][0] != '\n') {
    for (int j = 0; j < M; j++) {
      if (s[N][j] != '.') {
        char c = s[N][j];
        int idx = translate(c);
        loc[idx] = ii(N, j);
        count++;
      }
    }

    N++;
  }

  for (int k = 0; k < count - 1; k++) {
    ii l = loc[k], r = loc[k + 1];

    if (l.first != r.first) {
      int y = l.second;

      for (int i = min(l.first, r.first) + 1; i < max(l.first, r.first); i++) {
        if (s[i][y] == '.') {
          s[i][y] = '|';
        } else if (s[i][y] == '-') {
          s[i][y] = '+';
        }
      }
    } else {
      int x = l.first;

      for (int j = min(l.second, r.second) + 1; j < max(l.second, r.second);
           j++) {
        if (s[x][j] == '.') {
          s[x][j] = '-';
        } else if (s[x][j] == '|') {
          s[x][j] = '+';
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << s[i];
  }
  return true;
}

int main() {
  bool c = run();
  while (c) {
    cout << endl;
    c = run();
  }

  return 0;
}
