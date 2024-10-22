#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <sstream>

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

const ll N = 100010;

int n;

vector<vi> al(N);
vi p(N, -1);

map<string, int> idx;
map<int, string> str;
int k = 0;

inline int getidx(string s) {
  if (idx.count(s) == 0) {
    idx[s] = k;
    str[k] = s;
    return k++;
  }
  return idx[s];
}

void bfs(int s, int t) {
  queue<int> q;
  q.push(s);

  p[s] = s;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : al[u]) {
      if (p[v] == -1) {
        p[v] = u;
        q.push(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  string line;
  getline(cin, line);
  for (int i = 0; i < n; i++) {
    getline(cin, line);
    istringstream ss(line);

    string last, next;
    ss >> last;
    while (ss >> next) {
      int f = getidx(last), t = getidx(next);

      al[f].push_back(t);
      al[t].push_back(f);
    }
  }

  string ss, st;
  cin >> ss >> st;
  int s = getidx(ss), t = getidx(st);

  bfs(s, t);

  if (p[t] == -1) {
    cout << "no route found" << endl;
  } else {
    vi r;
    int u = t;

    while (p[u] != u) {
      r.push_back(u);
      u = p[u];
    }
    r.push_back(s);

    for (auto it = r.rbegin(); it != r.rend(); it++) {
      cout << str[*it] << " ";
    }
    cout << endl;
  }

  return 0;
}
