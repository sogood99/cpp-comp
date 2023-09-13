#include <bits/stdc++.h>
#include <cstdio>
#include <queue>

using namespace std;

char translate(char c) {
  if (c == 'R') {
    return 'S';
  } else if (c == 'B') {
    return 'K';
  } else if (c == 'L') {
    return 'H';
  }
  return 0;
}

int to_index(char c) {
  if (c == 'R') {
    return 0;
  } else if (c == 'B') {
    return 1;
  } else if (c == 'L') {
    return 2;
  }
  return -1;
}

int main() {
  int current_state[3] = {0, 0, 0};
  queue<char> buffer;

  char c;
  while ((c = getchar()) != EOF && c != '\n') {
    int i = to_index(c);
    if (current_state[i] > 0) {
      while (current_state[i] > 0) {
        char pc = buffer.front();
        char pi = to_index(pc);
        current_state[pi]--;
        cout << translate(pc);
        buffer.pop();
      }

      buffer.push(c);
      current_state[i]++;
    } else {
      current_state[i]++;
      buffer.push(c);

      if (buffer.size() == 3) {
        // RBL or any permutation
        cout << "C";
        while (!buffer.empty())
          buffer.pop();
        current_state[0] = current_state[1] = current_state[2] = 0;
      }
    }
  }

  while (!buffer.empty()) {
    cout << translate(buffer.front());
    buffer.pop();
  }
  cout << endl;

  return 0;
}
