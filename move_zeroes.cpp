#include <vector>
#include <iostream>

#include "helpers/pretty_print.cpp"

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) continue;

        int j = i + 1;

        while (j < nums.size()) {
          if (nums[j] != 0) {
            std::swap(nums[i], nums[j]);

            break;
          }

          j++;
        }
      }
    }
};

int main() {
  // Input: nums = [0,1,0,3,12]
  // Output: [1,3,12,0,0]
  std::vector<int> v1 { 0, 1, 0, 3, 12 };
  std::vector<int> v2 { 0 };

  Solution s;

  std::cout << "v1: " << v1 << std::endl;
  s.moveZeroes(v1);
  std::cout << "v1: " << v1 << std::endl;
  s.moveZeroes(v2);
  std::cout << "v2: " << v2 << std::endl;
}
