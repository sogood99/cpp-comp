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

char s[110], sub[110];
set<string> st;
int n, sub_idx = 0;

stack<char> stk;

void backtrack(int i, bool removed) {
  int j = i;

  if (removed) {
    for (; j < n; j++) {
      if (s[j] == '(') {
        // branch
        stack<char> stk_bak = stk;
        int old_idx = sub_idx;
        // remove s[j], push special char
        stk.push('*');
        backtrack(j + 1, true);

        // recover
        sub_idx = old_idx;
        stk = stk_bak;
        stk.push(s[j]);
        sub[sub_idx++] = s[j];
      } else if (s[j] == ')') {
        if (stk.top() != '*') {
          sub[sub_idx++] = s[j];
        }
        stk.pop();
      } else {
        sub[sub_idx++] = s[j];
      }
    }
    sub[sub_idx] = 0;
    st.insert(sub);
  } else {
    for (; j < n; j++) {
      if (s[j] == '(') {
        // branch
        stack<char> stk_bak = stk;
        int old_idx = sub_idx;
        // remove s[j]
        stk.push('*');
        backtrack(j + 1, true);

        // recover
        sub_idx = old_idx;
        stk = stk_bak;
        stk.push(s[j]);
        sub[sub_idx++] = s[j];
      } else if (s[j] == ')') {
        stk.pop();
        sub[sub_idx++] = s[j];
      } else {
        sub[sub_idx++] = s[j];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  n = strlen(s);

  backtrack(0, false);

  for (string ns : st) {
    cout << ns << endl;
  }

  return 0;
}
