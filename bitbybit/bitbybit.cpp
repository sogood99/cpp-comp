#include <bits/stdc++.h>
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

char b_and(char a, char b) {
  if (a == '?' && b == '?') {
    return '?';
  } else if (a == '?' || b == '?') {
    if (a == '?') {
      swap(a, b);
    }

    if (a == '0') {
      return '0';
    } else {
      return '?';
    }
  } else {
    int c = a - '0', d = b - '0';
    return (c & d) + '0';
  }
}

char b_or(char a, char b) {
  if (a == '?' && b == '?') {
    return '?';
  } else if (a == '?' || b == '?') {
    if (a == '?') {
      swap(a, b);
    }

    if (a == '1') {
      return '1';
    } else {
      return '?';
    }
  } else {
    int c = a - '0', d = b - '0';
    return (c | d) + '0';
  }
}

bool run() {
  int n;
  cin >> n;
  if (n == 0) {
    return false;
  }
  char bits[32];
  for (int i = 0; i < 32; i++) {
    bits[i] = '?';
  }

  int r1, r2;
  while (n--) {
    string op;
    cin >> op;
    if (op == "SET") {
      cin >> r1;
      bits[r1] = '1';
    } else if (op == "CLEAR") {
      cin >> r1;
      bits[r1] = '0';
    } else if (op == "AND") {
      cin >> r1 >> r2;
      bits[r1] = b_and(bits[r1], bits[r2]);
    } else { // op == "OR"
      cin >> r1 >> r2;
      bits[r1] = b_or(bits[r1], bits[r2]);
    }
  }

  for (int i = 31; i >= 0; i--) {
    cout << bits[i];
  }
  cout << endl;

  return true;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  while (run())
    ;

  return 0;
}
