#include <bits/stdc++.h>

using namespace std;

bool in_bounds(int x, int y) { return x >= 0 && x < 5 && y >= 0 && y < 5; }

int main() {
  char b[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> b[i][j];
    }
  }

  int count = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (b[i][j] == 'k') {
        count++;
        int x, y;

        x = i - 1, y = j - 2;
        if (in_bounds(x, y) && b[x][y] == 'k') {
          cout << "invalid" << endl;
          return 0;
        }
        x = i + 1, y = j - 2;
        if (in_bounds(x, y) && b[x][y] == 'k') {
          cout << "invalid" << endl;
          return 0;
        }

        x = i - 1, y = j + 2;
        if (in_bounds(x, y) && b[x][y] == 'k') {
          cout << "invalid" << endl;
          return 0;
        }
        x = i + 1, y = j + 2;
        if (in_bounds(x, y) && b[x][y] == 'k') {
          cout << "invalid" << endl;
          return 0;
        }

        x = i - 2, y = j - 1;
        if (in_bounds(x, y) && b[x][y] == 'k') {
          cout << "invalid" << endl;
          return 0;
        }
        x = i - 2, y = j + 1;
        if (in_bounds(x, y) && b[x][y] == 'k') {
          cout << "invalid" << endl;
          return 0;
        }

        x = i + 2, y = j - 1;
        if (in_bounds(x, y) && b[x][y] == 'k') {
          cout << "invalid" << endl;
          return 0;
        }
        x = i + 2, y = j + 1;
        if (in_bounds(x, y) && b[x][y] == 'k') {
          cout << "invalid" << endl;
          return 0;
        }
      }
    }
  }
  if (count == 9) {
    cout << "valid" << endl;
  } else {

    cout << "invalid" << endl;
  }
  return 0;
}
