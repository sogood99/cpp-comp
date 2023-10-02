#include <bits/stdc++.h>
#include <cstdio>

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

const ll max_size = 1e6;

struct node {
  node *next = nullptr;
  int index = -1;
};

int main() {
  int N;
  scanf("%d\n", &N);
  string *m = new string[N + 10];

  node **ll = new node *[N + 10];
  node **end = new node *[N + 10];

  char *s = new char[max_size];
  for (int i = 1; i <= N; i++) {
    scanf("%s", s);

    m[i] = s;
    // printf("%s\n", s);

    ll[i] = new node;
    ll[i]->index = i;
    ll[i]->next = nullptr;
    end[i] = ll[i];
  }

  int a = 1, b;
  for (int i = 0; i < N - 1; i++) {
    scanf("%d%d", &a, &b);

    end[a]->next = ll[b];
    end[a] = end[b];
  }

  node *root = ll[a];
  while (root != nullptr) {
    int idx = root->index;
    printf("%s", m[idx].c_str());
    root = root->next;
  }
  printf("\n");

  return 0;
}
