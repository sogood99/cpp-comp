#include <bits/stdc++.h>
#include <cstdio>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

typedef tuple<ll, ll, string> tp;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

bool cmp_tp(const tp &a, const tp &b) {

  ll k1 = get<1>(a), k2 = get<1>(b);
  ll v1 = get<0>(a), v2 = get<0>(b);
  while (k1 > k2) {
    v2 = v2 * 10 + 2;
    k2 *= 10;
  }
  while (k2 > k1) {
    v1 = v1 * 10 + 2;
    k1 *= 10;
  }

  if (v1 != v2) {
    return v1 > v2;
  }

  return get<2>(a) < get<2>(b);
}

void printTp(const vector<tp> &l) {
  for (auto a : l) {
    // cout << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << endl;
    printf("%s\n", get<2>(a).c_str());
  }
}

void run() {
  int N;
  scanf("%d\n", &N);
  char s[10], name[30];
  vector<tp> v;
  string s_name, ss;

  while (N--) {
    scanf("%s", name);
    s_name = name;
    s_name = s_name.substr(0, s_name.size() - 1);

    ll val = 0, k = 1;
    char c = getchar();
    do {
      scanf("%[^- ]s", s);
      ss = s;
      if (ss == "upper") {
        val += k * 3;
      } else if (ss == "middle") {
        val += k * 2;
      } else if (ss == "lower") {
        val += k * 1;
      }
      k *= 10;
    } while ((c = getchar() != ' '));
    scanf("%*s\n");

    tp t{val, k, s_name};
    v.push_back(t);
  }
  // printTp(v);
  sort(v.begin(), v.end(), cmp_tp);
  printTp(v);
  printf("==============================\n");
}

int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    run();
  }

  return 0;
}
