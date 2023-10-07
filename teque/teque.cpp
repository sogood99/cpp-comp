#include <bits/stdc++.h>
#include <cstdio>
#include <iterator>
#include <list>

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

void printList(list<int> &l) {
  for (int e : l) {
    printf("%d ", e);
  }
  printf("\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, x;
  scanf("%d", &N);
  string s;
  char c_s[10];

  list<int> l;
  // first elements
  scanf("%s %d\n", c_s, &x);
  l.push_front(x);

  printList(l);

  int m = 1;
  auto mid = l.end(), it = l.begin();
  while (N--) {
    scanf("%s %d\n", c_s, &x);
    printf("%s, %d\n", c_s, x);
    s = c_s;

    if (s == "push_back") {
      l.push_back(x);
    } else if (s == "push_front") {
      l.push_front(x);
      m++;
    } else if (s == "push_middle") {
      l.insert(mid, x);
      m++;
    } else if (s == "get") {
      it = l.begin();
      advance(it, x);
      printf("%d\n", *it);
    }

    while ((l.size() + 1) / 2 > m) {
      m++;
      mid++;
    }
    while ((l.size() + 1) / 2 < m) {
      m--;
      mid--;
    }
    printList(l);
  }

  return 0;
}
