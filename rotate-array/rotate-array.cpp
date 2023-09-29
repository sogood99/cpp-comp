
#include <bits/stdc++.h>
#include <vector>

using namespace std;

inline void swap_vec_el(vector<int> &nums, int i, int j) {
  int t = nums[i];
  nums[i] = nums[j];
  nums[j] = t;
}

void printArray(vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    const int N = nums.size();

    k = k % N;

    for (int i = 0; i < (N - k) / 2; i++) {
      swap_vec_el(nums, i, N - k - i - 1);
    }
    printArray(nums);

    for (int i = 0; i < k / 2; i++) {
      swap_vec_el(nums, N - i - 1, N - k + i);
    }

    printArray(nums);

    for (int i = 0; i < N / 2; i++) {
      swap_vec_el(nums, i, N - i - 1);
    }
    printArray(nums);
  }
};

int main() {

  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  Solution().rotate(nums, 6);
  printArray(nums);
}
