#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <cctype>

#define LSOne(S) ((S) & -(S))

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
private:
  int prec(const char c) {
    if (c == '*' || c == '/') {
      return 2;
    } else if (c == '+' || c == '-') {
      return 1;
    } else {
      return 0;
    }
  }

  int op(int a, int b, char o) {
    switch (o) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    }
    return 0;
  }

public:
  int calculate(string s) {
    vector<int> nums;
    vector<char> ops;

    int n = s.size();

    for (int i = 0; i < n; i++) {
      if (s[i] == ' ') {
        continue;
      } else if (isdigit(s[i])) {
        int t = 0;
        while (i < n && isdigit(s[i])) {
          t = t * 10 + (s[i++] - '0');
        }
        nums.push_back(t);
        i--;
      } else if (s[i] == '(') {
        ops.push_back('(');
      } else if (s[i] == ')') {
        while (ops.back() != '(') {
          int r = nums.back();
          nums.pop_back();
          int l = nums.back();
          nums.pop_back();
          char o = ops.back();
          ops.pop_back();
          nums.push_back(op(l, r, o));
        }
        ops.pop_back();
      } else {
        char c = s[i];
        while (!ops.empty() && prec(ops.back()) >= prec(c)) {
          int r = nums.back();
          nums.pop_back();
          int l = nums.back();
          nums.pop_back();
          char o = ops.back();
          ops.pop_back();
          nums.push_back(op(l, r, o));
        }

        ops.push_back(c);
      }
    }

    while (!ops.empty()) {
      int r = nums.back();
      nums.pop_back();
      int l = nums.back();
      nums.pop_back();
      char o = ops.back();
      ops.pop_back();
      nums.push_back(op(l, r, o));
    }

    return nums.back();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  cout << s.calculate("1+1*5*(1-6)") << endl;

  return 0;
}
