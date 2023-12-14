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

const int N = 2010;

enum { UNVISITED = 0, VISITED = 1 };

map<string, int> idx;
map<int, string> str;

vector<vi> al(N), al_T(N);
vi dfs_num(N, UNVISITED), S;

vector<bool> isperson(2010, false);

int n, m = 0, c = 0, cmax = 0;

void kosaraju(int u, int pass) {
  dfs_num[u] = VISITED;
  vector<vi> &neigh = (pass == 1) ? al : al_T;

  if (pass != 1 && isperson[u]) {
    c++;
  }

  for (int v : neigh[u]) {
    // cout << u << " " << v << endl;
    if (dfs_num[v] == UNVISITED) {
      kosaraju(v, pass);
    }
  }
  S.push_back(u);
}

int getidx(string s) {
  if (idx.count(s) == 0) {
    // cout << s << " : " << m << endl;
    idx[s] = m;
    return m++;
  }
  return idx[s];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  string l;
  getline(cin, l);
  for (int j = 0; j < n; j++) {
    getline(cin, l);

    istringstream is(l);

    string t;
    is >> t;

    int k = getidx(t);
    isperson[k] = true;

    is >> t;
    int q = getidx(t);
    al[q].push_back(k);
    al[k].push_back(q);
    al_T[q].push_back(k);
    al_T[k].push_back(q);

    while (is >> t) {
      q = getidx(t);
      al[q].push_back(k);
      al_T[k].push_back(q);
    }
  }

  for (int u = 0; u < m; u++) {
    if (dfs_num[u] == UNVISITED) {
      kosaraju(u, 1);
    }
  }
  // cout << S[m - 1] << endl;

  dfs_num.assign(N, UNVISITED);
  for (int j = m - 1; j >= 0; j--) {
    if (dfs_num[S[j]] == UNVISITED) {
      kosaraju(S[j], 2);
      // cout << "c " << c << endl;
      cmax = max(cmax, c);
      c = 0;
    }
  }

  cout << n - cmax << endl;

  return 0;
}
