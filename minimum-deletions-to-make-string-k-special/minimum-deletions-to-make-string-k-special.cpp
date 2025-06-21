#include <bits/extc++.h>
#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Solution {
public:
  int minimumDeletions(string word, int k) {
    unordered_map<char, int> freq;

    int total = word.size();

    for (char c : word) {
      freq[c]++;
    }

    vector<int> hist;

    for (auto p : freq) {
      hist.push_back(p.second);
    }

    sort(hist.begin(), hist.end());

    int j = 0, m = total, cnt_less = 0, cnt = 0, cnt_greater = total,
        freq_size = freq.size();

    for (int i = 0; i < hist.size(); i++) {
      if (i > 0) {
        cnt_less += hist[i - 1];
        cnt -= hist[i - 1];
      }

      while (j < hist.size() && hist[j] - hist[i] <= k) {
        cnt += hist[j];
        cnt_greater -= hist[j];
        j++;
      }

      m = min(m, cnt_less + cnt_greater - (hist[i] + k) * (freq_size - j));
    }

    return m;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
