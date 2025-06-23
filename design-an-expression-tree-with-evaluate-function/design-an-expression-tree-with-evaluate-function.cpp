#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <ios>
#include <unordered_map>

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

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
  Node() {}
  Node(Node *l, Node *r) : left(l), right(r) {}
  virtual ~Node() {
    if (left)
      delete left;
    if (right)
      delete right;
  };
  virtual int evaluate() const = 0;

protected:
  // define your fields here
  Node *left = nullptr, *right = nullptr;
};

class EvalNode : public Node {
private:
  string op;

public:
  EvalNode(Node *l, Node *r, string op) : Node(l, r), op(op) {}
  int evaluate() const override {
    auto &mp = getFunc();
    auto it = mp.find(op);
    return it->second(left->evaluate(), right->evaluate());
  }
  static const unordered_map<string, function<int(int, int)>> &getFunc() {
    static const unordered_map<string, function<int(int, int)>> mp = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }},
    };
    return mp;
  }
};

class ValNode : public Node {
private:
  int val = 0;

public:
  ValNode(int val) : val(val) {}
  int evaluate() const override { return val; }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree representing it as a Node.
 */

class TreeBuilder {
public:
  Node *buildTree(vector<string> &postfix) {
    vector<Node *> stk;

    for (string &s : postfix) {
      if (isdigit(s[0])) {
        int x = stoi(s);
        stk.push_back(new ValNode(x));
      } else {
        Node *right = stk.back();
        stk.pop_back();
        Node *left = stk.back();
        stk.pop_back();
        stk.push_back(new EvalNode(left, right, s));
      }
    }
    return stk.back();
  }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
