#include <algorithm>
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <sstream>

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

class SegmentTree {
  vector<int> st;
  int n;

public:
  SegmentTree(const vector<int> &A) {
    n = A.size();
    st.assign(4 * n, INT_MAX);
    build(A, 1, 0, n - 1);
  }

  void build(const vector<int> &A, int p, int L, int R) {
    if (L == R) {
      st[p] = A[L];
    } else {
      int mid = (L + R) / 2;
      build(A, 2 * p, L, mid);
      build(A, 2 * p + 1, mid + 1, R);
      st[p] = min(st[2 * p], st[2 * p + 1]);
    }
  }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }

  int rmq(int p, int L, int R, int i, int j) {
    if (i > R || j < L)
      return INT_MAX;
    if (L >= i && R <= j)
      return st[p];
    int mid = (L + R) / 2;
    return min(rmq(2 * p, L, mid, i, j), rmq(2 * p + 1, mid + 1, R, i, j));
  }
};

class Solution {
public:
  int longestCommonSubpath(int m, vector<vector<int>> &paths) {
    int n_paths = paths.size();
    vector<int> s, idx(n_paths);
    for (int i = 0; i < paths.size(); i++) {
      for (int j = 0; j < paths[i].size(); j++) {
        s.push_back(paths[i][j]);
      }
      s.push_back(-i - 1);
      idx[i] = s.size() - 1;
    }

    int n = s.size();

    vector<int> SA(n), RA(n), tRA(n);

    for (int i = 0; i < n; i++) {
      SA[i] = i;
      RA[i] = s[i];
    }

    for (int k = 1; k < n; k *= 2) {
      auto cmp = [&](const int a, const int b) {
        if (RA[a] != RA[b])
          return RA[a] < RA[b];
        int ra = (a + k < n) ? RA[a + k] : -1;
        int rb = (b + k < n) ? RA[b + k] : -1;
        return ra < rb;
      };
      sort(SA.begin(), SA.end(), cmp);

      tRA[SA[0]] = 0;
      for (int j = 1; j < n; j++) {
        tRA[SA[j]] = tRA[SA[j - 1]] + (cmp(SA[j - 1], SA[j]) ? 1 : 0);
      }
      swap(RA, tRA);
    }

    // construct LCP

    vector<int> LCP(n), PHI(n), PLCP(n);
    for (int i = 1; i < n; i++) {
      PHI[SA[i]] = SA[i - 1];
    }
    PHI[SA[0]] = -1;

    for (int i = 0, L = 0; i < n; i++) {
      if (PHI[i] == -1) {
        PLCP[i] = 0; // $
        continue;
      }
      while ((i + L < n) && (PHI[i] + L < n) && (s[i + L] == s[PHI[i] + L]))
        L++;

      PLCP[i] = L;
      L = max(L - 1, 0);
    }

    for (int i = 0; i < n; i++) {
      LCP[i] = PLCP[SA[i]];
    }

    // for (int i = 0; i < n; i++) {
    //   cout << i << ":" << s[i] << " ";
    // }
    // cout << endl;

    vector<int> cnt(n_paths, 0), group(n, 0);
    for (int i = 0; i < n; i++) {
      int g = lower_bound(idx.begin(), idx.end(), SA[i]) - idx.begin();
      group[i] = g;
      // cout << i << " " << SA[i] << " " << g << " " << LCP[i] << endl;
    }

    int i = 0, j = 0, n_g = 0;
    while (j < n && n_g < n_paths) {
      if (cnt[group[j]] == 0) {
        n_g++;
      }
      cnt[group[j]]++;
      j++;
    }

    int mx = 0;

    SegmentTree st(LCP);

    for (; j < n; j++) {
      cnt[group[j]]++;

      while (i < j && cnt[group[i]] > 1) {
        cnt[group[i]]--;
        i++;
      }
      // cout << "i:" << i << "j:" << j << endl;

      int minLCP = st.rmq(i + 1, j);
      // for (int k = i + 1; k <= j; k++) {
      //   minLCP = min(LCP[k], minLCP);
      // }

      mx = max(mx, minLCP);
    }
    return mx;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> paths = {{0, 1, 2, 3, 4}, {2, 3, 4}, {4, 0, 1, 2, 3}};
  Solution s;

  cout << s.longestCommonSubpath(5, paths) << endl;

  return 0;
}
