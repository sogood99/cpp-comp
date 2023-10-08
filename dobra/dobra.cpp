#include <algorithm>
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

vector<char> cons = {'A', 'E', 'I', 'O', 'U'};
vector<char> vow;

string s;
int n;

ll l_c = 0;

ll tc = 0, cc = 1;

bool iscons(char c) {
  return (c != '_') &&
         ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U'));
}
bool isvow(char c) { return (c != '_') && !iscons(c); }
bool isvowmod(char c) { return c == 'L' || c == 'V'; }

void backtrack(int i) {

  if (i == n) {
    if (l_c > 0) {
      tc += cc;
    }
    return;
  }

  int j = i;
  for (; j < n && s[j] != '_'; j++)
    ;

  if (s[j] != '_') {
    if (l_c > 0) {
      tc += cc;
    }
    return;
  }

  s[j] = 'C';
  if (j - 2 >= 0 && (s[j - 2] == 'C') && (s[j - 1] == 'C')) {

  } else if (j - 1 >= 0 && j + 1 < n && (s[j - 1] == 'C') &&
             (s[j + 1] == 'C')) {

  } else if (j + 2 < n && (s[j + 1] == 'C') && (s[j + 2] == 'C')) {

  } else {
    cc *= cons.size();
    backtrack(j + 1);
    cc /= cons.size();
  }
  s[j] = '_';

  s[j] = 'V';
  if (j - 2 >= 0 && isvowmod(s[j - 2]) && isvowmod(s[j - 1])) {

  } else if (j - 1 >= 0 && j + 1 < n && isvowmod(s[j - 1]) &&
             isvowmod(s[j + 1])) {

  } else if (j + 2 < n && isvowmod(s[j + 1]) && isvowmod(s[j + 2])) {

  } else {
    cc *= vow.size();
    backtrack(j + 1);
    cc /= vow.size();
  }
  s[j] = '_';

  char c = 'L';
  s[j] = c;
  if (j - 2 >= 0 && isvowmod(s[j - 2]) && isvowmod(s[j - 1])) {
  } else if (j - 1 >= 0 && j + 1 < n && isvowmod(s[j - 1]) &&
             isvowmod(s[j + 1])) {
  } else if (j + 2 < n && isvowmod(s[j + 1]) && isvowmod(s[j + 2])) {
  } else {
    l_c++;
    backtrack(j + 1);
    l_c--;
  }
  s[j] = '_';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  n = s.size();
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  for (char c : s) {
    if (c == 'L') {
      l_c++;
    }
  }

  // construct vow
  for (char c = 'A'; c <= 'Z'; c++) {
    if (find(cons.begin(), cons.end(), c) == cons.end() && c != 'L') {
      vow.push_back(c);
    }
  }

  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      s[i] = 'L';
    } else if (isvow(s[i])) {
      s[i] = 'V';
    } else if (iscons(s[i])) {
      s[i] = 'C';
    }
  }

  for (int j = 0; j < n; j++) {
    if (isvowmod(s[j])) {
      if (j - 2 >= 0 && isvowmod(s[j - 2]) && isvowmod(s[j - 1])) {
        cout << 0 << endl;
        return 0;
      } else if (j - 1 >= 0 && j + 1 < n && isvowmod(s[j - 1]) &&
                 isvowmod(s[j + 1])) {
        cout << 0 << endl;
        return 0;
      } else if (j + 2 < n && isvowmod(s[j + 1]) && isvowmod(s[j + 2])) {
        cout << 0 << endl;
        return 0;
      }
    } else if (s[j] == 'C') {
      if (j - 2 >= 0 && (s[j - 2] == 'C') && (s[j - 1] == 'C')) {
        cout << 0 << endl;
        return 0;
      } else if (j - 1 >= 0 && j + 1 < n && (s[j - 1] == 'C') &&
                 (s[j + 1] == 'C')) {
        cout << 0 << endl;
        return 0;
      } else if (j + 2 < n && (s[j + 1] == 'C') && (s[j + 2] == 'C')) {
        cout << 0 << endl;
        return 0;
      }
    }
  }

  backtrack(0);

  cout << tc << endl;

  return 0;
}
