#include <algorithm>
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <cstring>

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

struct node {
  node *l = nullptr, *r = nullptr;
  ll v = -1;
};

ll n, k;

node *build() {

  ll t;
  cin >> t;

  node *root = new node;
  root->v = t;

  for (ll i = 1; i < k; i++) {
    cin >> t;
    ll idx = 1;

    node *n = root;

    while (true) {
      if (n->v < t) {
        idx = 2 * idx + 1;
        if (n->r == nullptr) {
          n->r = new node;
          n->r->v = t;
          break;
        }
        n = n->r;
      } else {
        idx = 2 * idx;
        if (n->l == nullptr) {
          n->l = new node;
          n->l->v = t;
          break;
        }
        n = n->l;
      }
    }
  }
  return root;
}

bool checkTreeEq(const node *a, const node *b) {

  if ((a == nullptr) && (b == nullptr)) {
    return true;
  }
  if ((a == nullptr) != (b == nullptr)) {
    return false;
  }
  bool isnulll = a->l == nullptr, isnullr = a->r == nullptr,
       isnulllb = b->l == nullptr, isnullrb = b->r == nullptr;

  if (isnulll == isnulllb && isnullr == isnullrb) {
    const node *al = a->l, *ar = a->r, *bl = b->l, *br = b->r;
    return checkTreeEq(al, bl) && checkTreeEq(ar, br);
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  vector<node *> v(n);
  for (ll i = 0; i < n; i++) {
    node *b = build();
    v[i] = b;
  }

  int unique = n;

  bool *flag = new bool[n];
  fill_n(flag, n, false);

  for (int i = 0; i < n; i++) {
    if (flag[i]) {
      continue;
    }
    for (int j = i + 1; j < n; j++) {
      if (flag[j] == false && checkTreeEq(v[i], v[j])) {
        flag[j] = true;
        unique--;
      }
    }
  }

  cout << unique << endl;

  return 0;
}
