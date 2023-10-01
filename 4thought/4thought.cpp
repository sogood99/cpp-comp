#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>
#include <vector>

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

int compute(string s) {
  stack<int> stk;
  int a, b;
  for (char c : s) {
    if (c != '4') {
      a = stk.top();
      stk.pop();
      b = stk.top();
      stk.pop();
      if (c == '+') {
        stk.push(a + b);
      } else if (c == '-') {
        stk.push(b - a);
      } else if (c == '*') {
        stk.push(a * b);
      } else if (c == '/') {
        stk.push(b / a);
      }
    } else {
      stk.push(c - '0');
    }
  }

  return stk.top();
}

bool op_geq(char t, char c) {
  if (t == '/') {
    return true;
  }
  if (t == '*' && c != '/') {
    return true;
  }
  if (t == '+' && c != '/' && c != '*') {
    return true;
  }
  if (t == '-' && c == '-') {
    return true;
  }

  return false;
}

string to_postfix(string s) {
  string out;
  stack<char> stk;
  for (char c : s) {
    if (c == ' ') {
      continue;
    } else if (c != '4') {
      while (!stk.empty()) {
        char t = stk.top();
        if (op_geq(t, c)) {
          out += t;
          stk.pop();
        } else {
          break;
        }
      }
      stk.push(c);
    } else {
      out += c;
    }
  }
  while (!stk.empty()) {
    out += stk.top();
    stk.pop();
  }

  return out;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unordered_map<int, string> eval;

  const char ops[] = {'+', '-', '*', '/'};

  string s;
  for (char op1 : ops) {
    for (char op2 : ops) {
      for (char op3 : ops) {
        s = "4 ";
        s += op1;
        s += " 4 ";
        s += op2;
        s += " 4 ";
        s += op3;
        s += " 4 ";
        string postfix = to_postfix(s);
        int val = compute(postfix);

        // cout << s << " "
        // << " " << postfix << " " << val << endl;

        eval[val] = s;
      }
    }
  }

  int N, t;
  cin >> N;
  while (N--) {
    cin >> t;
    if (eval.count(t) == 0) {
      cout << "no solution" << endl;
    } else {
      cout << eval[t] << "= " << t << endl;
    }
  }

  return 0;
}
