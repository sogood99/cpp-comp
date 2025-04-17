#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <cctype>
#include <memory>
#include <type_traits>
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

struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  bool isDir;
  bool isFile;
  string content;

  TrieNode() {
    children = vector<shared_ptr<TrieNode>>(27);
    isDir = false;
    isFile = true;
  }

  TrieNode(bool isDir, bool isFile) : isDir(isDir), isFile(isFile) {
    children = vector<shared_ptr<TrieNode>>(27);
  }
};

vector<string> bfs_dir(shared_ptr<TrieNode> node) {
  node = node->children[26];

  if (!node) {
    return {};
  }

  queue<pair<shared_ptr<TrieNode>, string>> q;
  q.emplace(node, "");

  vector<string> res;

  while (!q.empty()) {
    auto [u, s] = q.front();
    q.pop();
    if (u->isFile || u->isDir) {
      res.push_back(s);
    }

    for (int i = 0; i < 26; i++) {
      auto v = u->children[i];
      if (v) {
        q.emplace(v, s + (char)('a' + i));
      }
    }
  }

  sort(res.begin(), res.end());
  return res;
}

class FileSystem {
  shared_ptr<TrieNode> root;

public:
  FileSystem() { root = make_shared<TrieNode>(true, false); }

  vector<string> ls(string path) {
    shared_ptr<TrieNode> node = root;
    string curr = "";
    if (path.size() != 1) {
      for (char c : path) {
        int i;
        if (c == '/') {
          // check that node is path
          if (!node->isDir) {
            return {};
          }
          curr = "";
          i = 26;
        } else {
          i = c - 'a';
          curr += c;
        }
        node = node->children[i];
        if (!node) {
          return {};
        }
      }
    }
    if (node->isFile) {
      return {curr};
    } else if (node->isDir) {
      return bfs_dir(node);
    }

    return {};
  }

  void mkdir(string path) {
    shared_ptr<TrieNode> node = root;
    if (path.size() != 1) {
      for (char c : path) {
        int i;
        if (c == '/') {
          // check that node is path
          if (!node->isDir) {
            node->isDir = true;
          }
          i = 26;
        } else {
          i = c - 'a';
        }

        if (!node->children[i]) {
          node->children[i] = make_shared<TrieNode>(false, false);
        }
        node = node->children[i];
      }
    }

    node->isDir = true;
  }

  void addContentToFile(string filePath, string content) {
    shared_ptr<TrieNode> node = root;
    for (char c : filePath) {
      int i;
      if (c == '/') {
        // check that node is path
        if (!node->isDir) {
          node->isDir = true;
        }
        i = 26;
      } else {
        i = c - 'a';
      }

      if (!node->children[i]) {
        node->children[i] = make_shared<TrieNode>(false, false);
      }
      node = node->children[i];
    }

    node->isFile = true;
    node->content += content;
  }

  string readContentFromFile(string filePath) {
    shared_ptr<TrieNode> node = root;
    for (char c : filePath) {
      int i;
      if (c == '/') {
        // check that node is path
        if (!node->isDir) {
          return "";
        }
        i = 26;
      } else {
        i = c - 'a';
      }

      if (!node->children[i]) {
        return "";
      }
      node = node->children[i];
    }

    return node->content;
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  FileSystem *obj = new FileSystem();

  obj->mkdir("/a/b/c/d");
  obj->addContentToFile("/a/b/cde", "Hello");

  for (auto s : obj->ls("/a/b")) {
    cout << s << endl;
  }

  cout << obj->readContentFromFile("/a/b/cde") << endl;

  return 0;
}
