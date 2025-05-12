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

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
  vector<NestedInteger> stk;
  vector<NestedInteger> nestedList;
  vector<NestedInteger>::iterator it;

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    this->nestedList = nestedList;
    this->it = this->nestedList.begin();
  }

  int next() {
    processNext();

    int x = stk.back().getInteger();
    stk.pop_back();
    return x;
  }

  void processNext() {
    while ((stk.empty() && it != nestedList.end()) ||
           (!stk.empty() && !stk.back().isInteger())) {
      if (stk.empty()) {
        stk.push_back(*it);
        it = std::next(it);
      } else {
        NestedInteger ni = stk.back();
        stk.pop_back();

        const vector<NestedInteger> &nil = ni.getList();

        for (int j = nil.size() - 1; j >= 0; j--) {
          stk.push_back(nil[j]);
        }
      }
    }
  }

  bool hasNext() {
    processNext();

    return !stk.empty();
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
