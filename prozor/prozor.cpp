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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int R, S, K;
  scanf("%d %d %d\n", &R, &S, &K);

  char t;
  int A[100][100], cv;
  char C[100][100];
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < S; j++) {
      t = getchar();
      C[i][j] = t;
      cv = t == '*' ? 1 : 0;
      A[i][j] = cv;
      if (j > 0)
        A[i][j] += A[i][j - 1];
      if (i > 0)
        A[i][j] += A[i - 1][j];
      if (i > 0 && j > 0)
        A[i][j] -= A[i - 1][j - 1];
    }
    t = getchar();
  }

  int cm = 0, bl = 0, br = 0;

  K -= 2;

  for (int i = K; i < R - 1; i++) {
    for (int j = K; j < S - 1; j++) {
      int subR = A[i][j] - A[i - K][j] - A[i][j - K] + A[i - K][j - K];
      if (cm < subR) {
        bl = i, br = j;
        cm = subR;
      }
    }
  }

  printf("%d\n", cm);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < S; j++) {
      if (i >= bl - K && i <= bl + 1 && j >= br - K && j <= br + 1) {
        if (i == bl + 1 || i == bl - K) {
          if (j == br + 1 || j == br - K) {
            printf("+");
          } else {
            printf("-");
          }
        } else if (j == br + 1 || j == br - K) {
          printf("|");
        } else {
          printf("%c", C[i][j]);
        }
      } else {
        printf("%c", C[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}
