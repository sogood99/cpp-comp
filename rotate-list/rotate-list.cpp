#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <optional>

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    int sz = 0;

    auto node = head;

    while (node) {
      sz++;
      node = node->next;
    }

    k = k % sz;

    for (int i = 0; i < k; i++) {
      head = rotateRight(head);
    }

    return head;
  }

  ListNode *rotateRight(ListNode *head) {
    ListNode *last = nullptr, *next = head;

    while (next->next) {
      last = next;
      next = next->next;
    }

    next->next = head;
    last->next = nullptr;

    return next;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
