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

class UnionFind {
private:
  vi p, rank, size;
  int numSets;

public:
  UnionFind(int N) {
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
      p[i] = i;

    rank.assign(N, 0);
    size.assign(N, 1);
    numSets = N;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int sizeOfSet(int i) { return size[findSet(i)]; }
  int unionSet(int i, int j) {
    if (isSameSet(i, j))
      return sizeOfSet(i);
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y])
      rank[y]++;
    size[y] += size[x];
    numSets--;
    return size[y];
  }
};

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }

    int n = nums.size(), ms = 1;
    UnionFind uf(n);
    map<int, int> numIndex;

    for (int i = 0; i < n; i++) {
      if (numIndex.count(nums[i]))
        continue;
      numIndex[nums[i]] = i;

      if (numIndex.count(nums[i] - 1)) {
        int j = numIndex[nums[i] - 1];

        int newSize = uf.unionSet(i, j);
        ms = max(ms, newSize);
      }

      if (numIndex.count(nums[i] + 1)) {
        int j = numIndex[nums[i] + 1];

        int newSize = uf.unionSet(i, j);
        ms = max(ms, newSize);
      }
    }

    return ms;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
