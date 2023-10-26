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

struct node {
  node *chr[26] = {nullptr};
  bool isEnd = false;
};

class Trie_w_Node {
private:
  node *root = new node;

public:
  Trie_w_Node() {}

  void insert(string word) {
    node *cn = root;
    for (char c : word) {
      node *&ptr = cn->chr[c - 'a'];
      if (ptr == nullptr) {
        ptr = new node;
        cn = ptr;
      } else {
        cn = ptr;
      }
    }
    cn->isEnd = true;
  }

  bool search(string word) {
    node *cn = root;
    for (char c : word) {
      node *&ptr = cn->chr[c - 'a'];
      if (ptr == nullptr) {
        return false;
      } else {
        cn = ptr;
      }
    }
    return cn->isEnd;
  }

  bool startsWith(string prefix) {
    node *cn = root;
    for (char c : prefix) {
      node *&ptr = cn->chr[c - 'a'];
      if (ptr == nullptr) {
        return false;
      } else {
        cn = ptr;
      }
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Trie {
private:
  int node[2010][26];
  bool isEnd[2010];
  int nn = 1;

public:
  Trie() {
    fill_n(&node[0][0], 2010 * 26, -1);
    fill_n(isEnd, 2010, false);
  }

  void insert(string word) {
    int cn = 0;
    for (char c : word) {
      int &nv = node[cn][c - 'a'];
      if (nv == -1) {
        nv = nn;
        nn++;
      }
      cn = nv;
    }
    isEnd[cn] = true;
  }

  bool search(string word) {
    int cn = 0;
    for (char c : word) {
      int &nv = node[cn][c - 'a'];
      if (nv == -1) {
        return false;
      }
      cn = nv;
    }
    return isEnd[cn];
  }

  bool startsWith(string prefix) {
    int cn = 0;
    for (char c : prefix) {
      if (node[cn][c - 'a'] == -1) {
        return false;
      }
      cn = node[cn][c - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Trie *obj = new Trie();
  obj->insert("apple");
  cout << obj->search("app") << endl;
  obj->insert("app");
  cout << obj->search("app") << endl;

  return 0;
}
