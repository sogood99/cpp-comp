#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

bool prefix_calc(string expr, bool p, bool q, bool r, bool s, bool t) {
  int n = expr.size();

  stack<bool> stk;

  for (int i = n - 1; i >= 0; i--) {
    bool op1, op2;
    switch (expr[i]) {
    case 'p':
      stk.push(p);
      break;
    case 'q':
      stk.push(q);
      break;
    case 'r':
      stk.push(r);
      break;
    case 's':
      stk.push(s);
      break;
    case 't':
      stk.push(t);
      break;
    case 'K':
      op2 = stk.top();
      stk.pop();
      op1 = stk.top();
      stk.pop();
      stk.push(op1 && op2);
      break;
    case 'A':
      op2 = stk.top();
      stk.pop();
      op1 = stk.top();
      stk.pop();
      stk.push(op1 || op2);
      break;
    case 'N':
      op1 = stk.top();
      stk.pop();
      stk.push(!op1);
      break;
    case 'C':
      op2 = stk.top();
      stk.pop();
      op1 = stk.top();
      stk.pop();
      stk.push(!op1 || op2);
      break;
    case 'E':
      op2 = stk.top();
      stk.pop();
      op1 = stk.top();
      stk.pop();
      stk.push(op1 == op2);
      break;
    }
  }

  return stk.top();
}

bool evalAll(string expr) {
  bool b_all[] = {false, true};
  for (bool p : b_all) {
    for (bool q : b_all) {
      for (bool r : b_all) {
        for (bool s : b_all) {
          for (bool t : b_all) {
            if (!prefix_calc(expr, p, q, r, s, t)) {
              // cout << p << q << r << s << t << endl;
              return false;
            }
          }
        }
      }
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char expr[110];
  while (1) {
    cin >> expr;
    if (expr[0] == '0') {
      break;
    }
    // cout << expr << endl;

    if (evalAll(expr)) {
      cout << "tautology" << endl;
    } else {
      cout << "not" << endl;
    }
  }

  return 0;
}
