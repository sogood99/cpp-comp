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
const int INF = 1e9;    // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18;  // 4*10^18 is < 2^63-1
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
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *odd_head = head, *even_head = head->next, *odd = head,
             *even = head->next;

    while (even->next != nullptr && even->next->next != nullptr) {
      ListNode *oddnext = odd->next->next, *evennext = even->next->next;
      odd->next = oddnext;
      even->next = evennext;
      odd = oddnext;
      even = evennext;
    }

    if (even->next != nullptr) {
      // three left
      odd->next = even->next;
      even->next = nullptr;
      odd->next->next = even_head;
    } else {
      // two left
      odd->next = even_head;
      even->next = nullptr;
    }

    return head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
