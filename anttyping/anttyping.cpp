#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <climits>

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

  string s;
  cin >> s;

  int fn = s[0] - '0';

  size_t n = s.length();

  // compute histogram from a to b
  ll hist[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      hist[i][j] = 0;
    }
  }

  for (size_t i = 0; i < n - 1; i++) {
    int a = s[i] - '0', b = s[i + 1] - '0';
    hist[a][b]++;
  }

  std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  ll total = 0, min_count = LLONG_MAX;

  do {
    int left = numbers[0];
    hist[left][fn]++;
    total = 0;
    for (int i = 0; i < 9; i++) {
      int a = numbers[i];
      total += hist[a][a];
      for (int k = 1; k + i < 9; k++) {
        int b = numbers[i + k];
        total += (k + 1) * (hist[a][b] + hist[b][a]);
      }
    }

    if (total < min_count) {
      min_count = total;
    }
    hist[left][fn]--;

  } while (std::next_permutation(numbers.begin(), numbers.end()));
  cout << min_count << endl;

  return 0;
}
