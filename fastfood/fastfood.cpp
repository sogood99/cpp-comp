#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 0; k < t; k++) {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<bool>> vec(n, vector<bool>(m, false));
    vector<int> prize(n, 0);
    vector<int> count(m, 0);

    int total = 0;

    for (int i = 0; i < n; i++) {
      int stick_count = 0;
      scanf("%d", &stick_count);
      for (int j = 0; j < stick_count; j++) {
        int stick_type = -1;
        scanf("%d", &stick_type);
        stick_type--;

        vec[i][stick_type] = true;
      }

      scanf("%d", &prize[i]);
    }
    for (int i = 0; i < m; i++) {
      scanf("%d", &count[i]);
    }

    for (int i = 0; i < n; i++) {
      int max_num = 10000;
      for (int j = 0; j < m; j++) {
        if (vec[i][j] == true) {
          max_num = min(max_num, count[j]);
        }
      }
      total += max_num * prize[i];

      for (int j = 0; j < m; j++) {
        if (vec[i][j] == true) {
          count[j] -= max_num;
        }
      }
    }
    printf("%d\n", total);
  }

  return 0;
}
