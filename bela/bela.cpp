#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main() {
  // 0 = dominant, 1 = not dominant
  int value[8][2] = {{11, 11}, {4, 4},  {3, 3}, {20, 2},
                     {10, 10}, {14, 0}, {0, 0}, {0, 0}},
      N;

  map<char, int> m;
  m['A'] = 0;
  m['K'] = 1;
  m['Q'] = 2;
  m['J'] = 3;
  m['T'] = 4;
  m['9'] = 5;
  m['8'] = 6;
  m['7'] = 7;

  char B;

  cin >> N >> B;
  string card;
  int total_score = 0;

  for (int i = 0; i < 4 * N; i++) {
    cin >> card;

    if (card[1] == B) {
      total_score += value[m[card[0]]][0];
    } else {
      total_score += value[m[card[0]]][1];
    }
  }
  cout << total_score << endl;

  return 0;
}
