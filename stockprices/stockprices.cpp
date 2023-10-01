#include <bits/stdc++.h>
#include <queue>
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

void run() {

  priority_queue<ii, vector<ii>, less<ii>> buy;
  priority_queue<ii, vector<ii>, greater<ii>> sell;

  int n;
  cin >> n;
  int sp = -1;
  while (n--) {
    string s, s1, s2; // temp string
    int c, p;

    cin >> s >> c >> s1 >> s2 >> p;

    if (s == "buy") {
      buy.push({p, c});
    } else if (s == "sell") {
      sell.push({p, c});
    }

    while (!buy.empty() && !sell.empty() &&
           buy.top().first >= sell.top().first) {
      sp = sell.top().first;
      int bs = buy.top().second, ss = sell.top().second;
      if (bs == ss) {
        buy.pop();
        sell.pop();
      } else if (bs > ss) {
        int bp = buy.top().first;
        sell.pop();
        buy.pop();
        buy.push({bp, bs - ss});
      } else if (bs < ss) {
        sell.pop();
        buy.pop();
        sell.push({sp, ss - bs});
      }
    }

    (sell.empty() ? (cout << "-") : (cout << sell.top().first));
    (buy.empty() ? (cout << " -") : (cout << " " << buy.top().first));
    (sp == -1 ? (cout << " -") : (cout << " " << sp));
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  while (N--) {
    run();
  }
  return 0;
}
