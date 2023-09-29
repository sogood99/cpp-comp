#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

typedef std::vector<int> vi;

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int k = m + n - 1, i = m - 1, j = n - 1;

    while (j >= 0) {
      if ((i >= 0 && nums1[i] > nums2[j])) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
  }
};

int main() {
  vi A(10), B(5);

  for (int i = 0; i < 5; i++) {
    A[i] = 2 + i;
    B[i] = i + 1;
  }

  Solution().merge(A, 5, B, 5);

  for (int i = 0; i < 10; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}
