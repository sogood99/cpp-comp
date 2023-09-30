#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class UnionFind {

private:
  vi p, rank, setSize;
  int numSets;

public:
  UnionFind(int N) {
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
      p[i] = i;
    rank.assign(N, 0);
    setSize.assign(N, 1);
    numSets = N;
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }

  void unionSet(int i, int j) {
    if (isSameSet(i, j))
      return;
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y])
      rank[y]++;
    setSize[y] += setSize[x];
    numSets--;
  }
};

int main() {
  int N, Q;
  scanf("%d %d\n", &N, &Q);
  UnionFind ufds(N);

  char c;
  int i, j;
  for (int k = 0; k < Q; k++) {
    scanf("%c %d %d\n", &c, &i, &j);
    if (c == '?') {
      printf("%s\n", (ufds.isSameSet(i, j) ? "yes" : "no"));
    } else if (c == '=') {
      ufds.unionSet(i, j);
    }
  }

  return 0;
}
