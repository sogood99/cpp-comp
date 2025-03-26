#include <algorithm>
#include <bits/extc++.h>
#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))
#define N 1 << 18

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

ll sliding_window(string &s) {
  size_t n = s.length();

  ll total = 0;

  for (int i = 0; i < n; i++) {
    ll max_digit = 0;
    for (int j = i; j < n; j++) {
      ll num = s[j] - '0';
      max_digit = max(max_digit, num);
      total += max_digit;
    }
  }

  return total;
}

int t[4 * N], a[N];

ll build_seg_tree(int a[], int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
    return t[v];
  } else {
    int tm = (tl + tr) / 2;
    ll sm = 0;
    sm += build_seg_tree(a, v * 2, tl, tm);
    sm += build_seg_tree(a, v * 2 + 1, tm + 1, tr);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
    sm += t[v];
    return sm;
  }
}

ll get_val(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return get_val(v * 2, tl, tm, l, min(r, tm)) +
         get_val(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  ll n = s.length();
  // ll total = sliding_window(s);
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - '0';
  }
  ll total = build_seg_tree(a, 1, 0, n - 1);
  ll total_count = n * (n + 1) / 2;

  if (total % total_count == 0) {
    cout << total / total_count << endl;
  } else {
    ll g = gcd(total, total_count), r = total % total_count;
    ll t = total / total_count;
    if (t > 0) {
      cout << total / total_count << " " << r / g << "/" << total_count / g
           << endl;
    } else {
      cout << r / g << "/" << total_count / g << endl;
    }
  }

  return 0;
}
