#include <bits/stdc++.h>
#include <cstdio>
#include <set>
#include <unordered_set>
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
  const int N = 500010;
  int Q;
  UnionFind ufds(N);
  scanf("%d", &Q);

  int count = 0;
  for (int i = 0; i < Q; i++) {
    unordered_set<int> s;
    int size;
    // check that sum(sizeOfSet(s)) == size
    scanf("%d", &size);

    int j; // ingredient
    for (int i = 0; i < size; i++) {
      scanf("%d", &j);
      s.insert(ufds.findSet(j));
    }
    int t = 0;
    for (int k : s) {
      t += ufds.sizeOfSet(k);
      if (t > size) {
        s.clear();
        break;
      }
    }

    if (t == size) {
      // concoct
      count++;
      int idx = *s.begin();

      for (int j : s) {
        ufds.unionSet(idx, j);
      }
    }
  }
  printf("%d\n", count);

  return 0;
}
