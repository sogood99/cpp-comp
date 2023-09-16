#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  bool u_s = false, d_s = false, l_s = false;
  int u = 0, d = 0, l = 0;

  char c;
  scanf("%c", &c);
  if (c == 'U') {
    u_s = d_s = l_s = true;
  } else {
    u_s = d_s = l_s = false;
  }

  while (scanf("%c", &c) != EOF) {
    if (c != 'U' && c != 'D') {
      break;
    }
    if (c == 'U') {
      if (u_s == true) {
        // do nothing
      } else {
        u++;
      }
      u_s = true;

      if (d_s == true) {
        d++;
      } else {
        d += 2;
      }
      d_s = false;

      if (l_s == true) {
        // nothing
      } else {
        l++;
      }
      l_s = true;
    } else {
      if (u_s == true) {
        u += 2;
      } else {
        u++;
      }
      u_s = true;

      if (d_s == true) {
        d++;
      } else {
        // do nothing
      }
      d_s = false;

      if (l_s == true) {
        l++;
      } else {
        // nothing
      }
      l_s = false;
    }
  }

  cout << u << endl << d << endl << l << endl;

  return 0;
}
