ainclude<bits / extc++.h>
#include <bits/stdc++.h>

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

enum { UNVISITED = -1, EXPLORED = 2, CYCLE = 1, NOCYCLE = 0 };

vector<vi> al(5000);
map<string, int> mp;
vi tc(5000, -1);

bool cycleCheck(int j) {
  if (tc[j] == EXPLORED) {
    tc[j] = CYCLE;
    return CYCLE;
  } else if (tc[j] != UNVISITED) {
    return tc[j];
  }

  tc[j] = EXPLORED;

  int cv = NOCYCLE;
  for (int u : al[j]) {
    cv = cv || cycleCheck(u);
  }
  tc[j] = cv;
  return cv;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int cc = 0;

  string s, d;
  for (int i = 0; i < n; i++) {
    cin >> s >> d;
    int f, t;
    if (mp.count(s) == 0) {
      f = cc;
      mp[s] = cc++;
    } else {
      f = mp[s];
    }

    if (mp.count(d) == 0) {
      t = cc;
      mp[d] = cc++;
    } else {
      t = mp[d];
    }

    al[f].push_back(t);
  }

  while (cin >> s) {
    cout << s << " ";
    if (cycleCheck(mp[s])) {
      cout << "safe";
    } else {
      cout << "trapped";
    }
    cout << endl;
  }

  return 0;
}
