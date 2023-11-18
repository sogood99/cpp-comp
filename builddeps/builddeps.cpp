#include <bits/extc++.h>
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

vector<vi> al(100010);
map<string, int> mp;
map<int, string> mps;
int n, cc = 0;

vi v;

vector<bool> visited(100010, false);

void dfs(int j) {

  for (int u : al[j]) {
    if (!visited[u]) {
      visited[u] = true;
      dfs(u);
    }
  }

  v.push_back(j);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string line, s;

  getline(cin, line);
  istringstream iss(line);
  iss >> n;

  while (n-- && getline(cin, line)) {
    istringstream iss(line);
    iss >> s;
    s = s.substr(0, s.size() - 1);

    int f, t;

    if (mp.count(s) == 0) {
      mp[s] = cc;
      f = cc++;
      mps[f] = s;
    } else {
      f = mp[s];
    }

    while (iss >> s) {
      if (mp.count(s) == 0) {
        mp[s] = cc;
        t = cc++;
        mps[t] = s;
      } else {
        t = mp[s];
      }

      al[t].push_back(f);
    }
  }

  getline(cin, line);
  iss = istringstream(line);
  iss >> s;

  dfs(mp[s]);

  for (auto it = v.rbegin(); it != v.rend(); it++) {
    cout << mps[*it] << endl;
  }

  return 0;
}
