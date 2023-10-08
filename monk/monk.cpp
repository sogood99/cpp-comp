#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<dd> vdd;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

const int iter = 500000;

int a, d;
vd t_h, t_t, t_sh, t_st;
vd f_h, f_t, f_sh, f_st;
double t1, t2;
double h_t;

int i1 = 0, i2 = 0;
double cd1 = 0, cd2 = 0;

bool can(double l, double r) {

  double d1 = cd1, d2 = cd2;
  bool geq = (d1 >= h_t - d2), leq = (d1 <= h_t - d2);

  // cout << "FOR" << l << " " << r << endl;
  // cout << l << " " << d1 << " " << h_t - d2 << endl;

  int i = i1, j = i2;
  while (i < a && j < d && l < r) {
    double t_next_1 = t_st[i + 1] - l;
    double t_next_2 = f_st[j + 1] - l;
    double t_end = r - l;
    if (t_end <= t_next_1 && t_end <= t_next_2) {
      d1 += t_h[i] / t_t[i] * t_end;
      d2 += f_h[j] / f_t[j] * t_end;
      l += t_end;
    } else {
      if (t_next_1 <= t_next_2) {
        d1 = t_sh[++i];
        d2 += f_h[j] / f_t[j] * t_next_1;
        l += t_next_1;
      } else {
        d1 += t_h[i] / t_t[i] * t_next_2;
        d2 = f_sh[++j];
        l += t_next_2;
      }
    }
    geq |= (d1 >= h_t - d2);
    leq |= (d1 <= h_t - d2);
    // cout << l << " ";
    // cout << d1 << " " << h_t - d2 << endl;
  }

  while (i < a && l < r) {
    double t_next_1 = t_st[i + 1] - l;
    double t_end = r - l;
    if (t_end <= t_next_1) {
      l = r;
      d1 += t_h[i] / t_t[i] * t_end;
    } else {
      l += t_next_1;
      d1 = t_sh[++i];
    }
    geq |= (d1 >= h_t - d2);
    leq |= (d1 <= h_t - d2);
  }

  while (j < d && l < r) {
    double t_next_2 = f_st[j + 1] - l;
    double t_end = r - l;
    if (t_end <= t_next_2) {
      l = r;
      d2 += f_h[j] / f_t[j] * t_end;
    } else {
      l += t_next_2;
      d2 = f_sh[++j];
    }
    geq |= (d1 >= h_t - d2);
    leq |= (d1 <= h_t - d2);
  }

  bool ret = geq && leq;
  if (!ret) {
    cd1 = d1, cd2 = d2;
    i1 = i, i2 = j;
  }

  return ret;
}

double bins(double l, double r) {
  for (int i = 0; i < iter; i++) {
    double m = (l + r) / 2.;

    if (can(l, m)) {
      r = m;
    } else {
      l = m;
    }
  }

  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> d;

  double hi, tm;

  double sh = 0, st = 0;
  t_sh.push_back(sh);
  t_st.push_back(st);
  for (int i = 0; i < a; i++) {
    cin >> hi >> tm;
    t_h.push_back(hi);
    t_t.push_back(tm);
    sh += hi, st += tm;
    t_sh.push_back(sh);
    t_st.push_back(st);
  }
  t1 = st;

  st = sh = 0;
  f_sh.push_back(sh);
  f_st.push_back(st);
  for (int i = 0; i < d; i++) {
    cin >> hi >> tm;
    f_h.push_back(hi);
    f_t.push_back(tm);
    sh += hi, st += tm;
    f_sh.push_back(sh);
    f_st.push_back(st);
  }
  t2 = st;

  h_t = t_sh[a];

  cout << setprecision(20) << bins(0, min(t1, t2)) << endl;

  return 0;
}
