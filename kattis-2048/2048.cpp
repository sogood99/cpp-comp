#include <bits/stdc++.h>
#include <stack>

using namespace std;

struct ib {
  int value = 0;
  bool changed = false;

  ib(int i) {
    this->value = i;
    this->changed = false;
  }
};

bool operator==(const ib &lhs, const ib &rhs) {
  return (lhs.changed == false && lhs.value == rhs.value);
}

bool operator==(const ib &lhs, const int &rhs) {
  return (lhs.changed == false && lhs.value == rhs);
}

void push_stack(stack<ib> &s, int A[4][4], int i, int j) {
  if (A[i][j] != 0) {
    if (!s.empty() && s.top() == A[i][j]) {
      s.pop();
      ib new_ib = A[i][j] * 2;
      new_ib.changed = true;
      s.push(new_ib);
    } else {
      s.push(A[i][j]);
    }
  }
}

int main() {

  int A[4][4];

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> A[i][j];
    }
  }

  int t;
  cin >> t;
  stack<ib> s;
  if (t == 0) {
    // left
    for (int r = 0; r < 4; r++) {
      for (int j = 0; j < 4; j++) {
        push_stack(s, A, r, j);
      }

      int sz = s.size();
      for (int j = sz - 1; j >= 0; j--) {
        A[r][j] = s.top().value;
        s.pop();
      }
      for (int j = sz; j < 4; j++) {
        A[r][j] = 0;
      }
    }

  } else if (t == 1) {
    // up

    for (int c = 0; c < 4; c++) {
      for (int i = 0; i < 4; i++) {
        push_stack(s, A, i, c);
      }

      int sz = s.size();
      for (int i = sz - 1; i >= 0; i--) {
        A[i][c] = s.top().value;
        s.pop();
      }
      for (int i = sz; i < 4; i++) {
        A[i][c] = 0;
      }
    }
  } else if (t == 2) {
    // right
    for (int r = 0; r < 4; r++) {
      for (int j = 3; j >= 0; j--) {
        push_stack(s, A, r, j);
      }

      int sz = s.size();
      for (int j = 4 - sz; j < 4; j++) {
        A[r][j] = s.top().value;
        s.pop();
      }
      for (int j = 0; j < 4 - sz; j++) {
        A[r][j] = 0;
      }
    }

  } else if (t == 3) {
    // down
    for (int c = 0; c < 4; c++) {
      for (int i = 3; i >= 0; i--) {
        push_stack(s, A, i, c);
      }

      int sz = s.size();
      for (int i = 4 - sz; i < 4; i++) {
        A[i][c] = s.top().value;
        s.pop();
      }
      for (int i = 0; i < 4 - sz; i++) {
        A[i][c] = 0;
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
