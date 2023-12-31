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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *lhead = list1, *rhead = list2;

    ListNode temp_head = ListNode(0), *start = &temp_head, *node = start;

    while (lhead != nullptr && rhead != nullptr) {
      if (lhead->val < rhead->val) {
        node->next = lhead;
        lhead = lhead->next;
      } else {
        node->next = rhead;
        rhead = rhead->next;
      }
      node = node->next;
    }

    while (lhead != nullptr) {
      node->next = lhead;
      lhead = lhead->next;
      node = node->next;
    }

    while (rhead != nullptr) {
      node->next = rhead;
      rhead = rhead->next;
      node = node->next;
    }

    return start->next;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
