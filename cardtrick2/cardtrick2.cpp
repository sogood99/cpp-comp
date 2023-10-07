#include <bits/stdc++.h>
#include <queue>

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

vector<vi> v = {{1},
                {2, 1},
                {3, 1, 2},
                {2, 1, 4, 3},
                {3, 1, 4, 5, 2},
                {4, 1, 6, 3, 2, 5},
                {5, 1, 3, 4, 2, 6, 7},
                {3, 1, 7, 5, 2, 6, 8, 4},
                {7, 1, 8, 6, 2, 9, 4, 5, 3},
                {9, 1, 8, 5, 2, 4, 7, 6, 3, 10},
                {5, 1, 6, 4, 2, 10, 11, 7, 3, 8, 9},
                {7, 1, 4, 9, 2, 11, 10, 8, 3, 6, 5, 12},
                {4, 1, 13, 11, 2, 10, 6, 7, 3, 5, 12, 9, 8}};

void printPrecompute(int n) {
  for (int i = 0; i < n - 1; i++) {
    cout << v[n - 1][i] << " ";
  }
  cout << v[n - 1][n - 1] << endl;
}

// int A[15];
//
// void printArr(int n) {
//   cout << "{ ";
//   for (int i = 0; i < n - 1; i++) {
//     cout << A[i] << ", ";
//   }
//   cout << A[n - 1] << " }" << endl;
// }
//
// void printQ(deque<int> &q) {
//   for (auto e : q) {
//     cout << e << " ";
//   }
//   cout << endl;
// }
//
// bool run(int k) {
//   deque<int> q;
//   // cout << " ================= " << endl;
//   for (int i = 0; i < k; i++) {
//     q.push_back(A[i]);
//   }
//
//   int c = 1;
//   while (c <= k) {
//     // printQ(q);
//     for (int i = 0; i < c; i++) {
//       q.push_back(q.front());
//       q.pop_front();
//     }
//     // printQ(q);
//     if (q.front() != c) {
//       // cout << (q.front() == c) << q.front() << "this" << c << endl;
//       return false;
//     } else {
//       q.pop_front();
//     }
//     c++;
//   }
//   return true;
// }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  // for (int n = 1; n <= 13; n++) {
  //   cout << n << ":" << endl;
  //   for (int i = 1; i <= n; i++) {
  //     A[i - 1] = i;
  //   }
  //
  //   do {
  //     // printArr(n);
  //     if (run(n)) {
  //       // vi vt(n, 0);
  //       // for (int j = 0; j < n; j++) {
  //       //   vt[j] = A[j];
  //       // }
  //       // v.push_back(vt);
  //       printArr(n);
  //       break;
  //     }
  //   } while (next_permutation(A, A + n));
  // }

  while (T--) {
    int n;
    cin >> n;
    // printArr(n);
    printPrecompute(n);
  }

  return 0;
}
