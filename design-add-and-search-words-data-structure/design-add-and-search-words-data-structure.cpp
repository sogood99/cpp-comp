#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <vector>

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

typedef vector<int> vi;

inline int idx(char c) {
  if (c >= 'a' && c <= 'z')
    return c - 'a';
  if (c >= 'A' && c <= 'Z')
    return c - 'A' + 26;
  return -1;
}

class WordDictionary {
private:
  vector<vi> trie;
  vector<bool> isMax;
  int curr_max = 1;

public:
  WordDictionary() {
    trie.assign(2048, vi(52, -1));
    isMax.assign(2048, false);
  }

  void addWord(string word) {
    int curr_idx = 0;
    for (const char c : word) {
      int i = idx(c);
      if (trie[curr_idx][i] == -1) {
        trie[curr_idx][i] = curr_max++;
        trie.push_back(vi(52, -1));
        isMax.push_back(false);
      }

      curr_idx = trie[curr_idx][i];
    }
    isMax[curr_idx] = true;
  }

  bool search(string word) { return backtrack(0, 0, word); }

  bool backtrack(int j, int curr_idx, string &word) {
    if (curr_idx == -1)
      return false;
    bool rt = false;
    while (j < word.size()) {
      if (word[j] == '.') {
        for (int i = 0; i < 26 * 2; i++) {
          rt = rt || backtrack(j + 1, trie[curr_idx][i], word);
          if (rt)
            break;
        }
        return rt;
      } else {
        int i = idx(word[j]);
        if (trie[curr_idx][i] == -1) {
          return false;
        }
        curr_idx = trie[curr_idx][i];
        j++;
      }
    }
    return isMax[curr_idx];
  }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
