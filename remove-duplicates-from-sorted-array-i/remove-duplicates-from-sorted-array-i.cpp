#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int k = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
      if (i == 0 || nums[i] != nums[k - 1] || !checkG2(nums, k)) {
        nums[k++] = nums[i];
      }
    }

    return k;
  }

private:
  bool checkG2(vector<int> &nums, int k) {
    if (k >= 2 && nums[k - 1] == nums[k - 2]) {
      return true;
    }

    return false;
  }
};

int main() {
  vector<int> nums = {1, 2, 2, 2, 3, 3, 4, 5};

  Solution().removeDuplicates(nums);

  return 0;
}
