#include <iostream>
#include <vector>
#include <math.h>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
      auto start = nums.begin();
      auto end = nums.end();
      auto half = start + (end - start)/2;

      while ((start + 1) != end) {
        if (*half == target) return half - nums.begin();

        if (*half > target) {
          end = half;
        } else if (*half < target) {
          start = half;
        }

        half = start + ceil((end - start)/2.0);
      }

      return (*start >= target)
        ? (start - nums.begin())
        : (end - nums.begin());
    }
};
























int main() {
  // Input: nums = [1,3,5,6], target = 5
  // Output: 2
  std::vector<int> nums = {1,3,5,6};
  int target = 5;

  // [1,3,5,6]
  // 2
  std::vector<int> nums2 = {1,3,5,6};
  int target2 = 0;

  // [1]
  // 1
  std::vector<int> nums3 = {1};
  int target3 = 1;



  Solution s;

  std::cout << s.searchInsert(nums, target);

  std::cout << "\n-----------------\n";
  std::cout << s.searchInsert(nums2, target2);

  std::cout << "\n-----------------\n";
  std::cout << s.searchInsert(nums3, target3);
}
