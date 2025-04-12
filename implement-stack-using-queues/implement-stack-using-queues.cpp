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

class MyStack {
  queue<int> q;

public:
  MyStack() {}

  void push(int x) {
    int n = q.size();
    q.push(x);

    for (int i = 0; i < n; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    int val = q.front();
    q.pop();
    return val;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
