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

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *prev = nullptr, *node = head;

    ListNode *lhead, *rhead, *first, *last;

    int i = 1;
    for (; i < left; i++) {
      prev = node;
      node = node->next;
    }
    lhead = prev;
    first = node;

    i++;
    prev = node;
    node = node->next;

    for (; i <= right; i++) {
      ListNode *tnode = node->next;
      node->next = prev;

      prev = node;
      node = tnode;
    }
    last = prev;
    rhead = node;

    first->next = rhead;
    if (lhead == nullptr) {
      return last;
    } else {
      lhead->next = last;
      return head;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
