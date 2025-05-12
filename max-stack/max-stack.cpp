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

// O(1) for top, O(log n) for else
class MaxStack {
private:
  map<int, vector<list<int>::iterator>> mp;
  list<int> lst;

public:
  MaxStack() {}

  void push(int x) {
    lst.push_back(x);

    auto it = prev(lst.end());

    mp[x].push_back(it);
  }

  int pop() {
    int x = lst.back(); // O(1)
    lst.pop_back();     // O(1)
    mp[x].pop_back();   // O(log n)
    if (mp[x].size() == 0) {
      mp.erase(x);
    }
    return x;
  }

  int top() {
    return lst.back(); // O(1)
  }

  int peekMax() {
    auto p = prev(mp.end());
    return p->first;
  }

  int popMax() {
    auto p = prev(mp.end());
    int x = p->first;
    auto list_it = p->second.back();
    p->second.pop_back();

    lst.erase(list_it);

    if (p->second.empty()) {
      mp.erase(p);
    }
    return x;
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  MaxStack stk = MaxStack();
  stk.push(5);       // [5] the top of the stack and the maximum number is 5.
  stk.push(1);       // [5, 1] the top of the stack is 1, but the maximum is 5.
  stk.push(5);       // [5, 1, 5] the top of the stack is 5, which is also the
                     // maximum, because it is the top most one.
  cout << stk.top(); // return 5, [5, 1, 5] the stack did not change.
  cout << stk.popMax();  // return 5, [5, 1] the stack is changed now, and the
                         // top is different from the max.
  cout << stk.top();     // return 1, [5, 1] the stack did not change.
  cout << stk.peekMax(); // return 5, [5, 1] the stack did not change.
  cout << stk.pop(); // return 1, [5] the top of the stack and the max element
                     // is now 5.
  cout << stk.top(); // return 5, [5] the stack did not change.

  return 0;
}
