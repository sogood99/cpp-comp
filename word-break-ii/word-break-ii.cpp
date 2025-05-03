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
private:
  vector<vector<pair<int, int>>> memo;
  vector<bool> lazy;

  bool matches(string &s, int j, string &p) {
    int n = p.size();
    if (j < n - 1) {
      return false;
    }

    for (int i = 0; i < n; i++) {
      if (s[j - i] != p[n - i - 1]) {
        return false;
      }
    }
    return true;
  }

  bool dp(int j, string &s, vector<string> &wordDict) {
    if (j == -1) {
      return true;
    }

    if (lazy[j]) {
      return !memo[j].empty();
    }

    for (int i = 0; i < wordDict.size(); i++) {
      string &word = wordDict[i];
      int k = word.size();
      if (matches(s, j, word) && dp(j - k, s, wordDict)) {
        memo[j].push_back({j - k, i});
      }
    }
    lazy[j] = true;

    return !memo[j].empty();
  }

public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    memo = vector<vector<pair<int, int>>>(n);
    lazy = vector<bool>(n);

    if (!dp(n - 1, s, wordDict)) {
      return {};
    }

    vector<string> res;

    vector<pair<int, string>> q;
    q.push_back({n - 1, ""});

    while (!q.empty()) {
      auto [j, cs] = q.back();
      q.pop_back();

      if (j == -1) {
        res.push_back(cs);
      } else {
        for (auto [l, i] : memo[j]) {
          q.push_back({l, j == n - 1 ? wordDict[i] : wordDict[i] + " " + cs});
        }
      }
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
