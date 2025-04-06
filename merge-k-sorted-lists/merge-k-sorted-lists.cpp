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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();

    ListNode *root = nullptr, *curr = nullptr;
    std::priority_queue<ii, vector<ii>, greater<ii>> pq;

    for (int i = 0; i < n; i++) {
      if (lists[i]) {
        pq.emplace(lists[i]->val, i);
      }
    }

    while (!pq.empty()) {
      auto [v, i] = pq.top();
      pq.pop();
      if (!root) {
        root = lists[i];
        curr = lists[i];
      } else {
        curr->next = lists[i];
        curr = lists[i];
      }

      lists[i] = curr->next;
      curr->next = nullptr;
      if (lists[i]) {
        // push onto pq
        pq.emplace(lists[i]->val, i);
      }
    }

    return root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
