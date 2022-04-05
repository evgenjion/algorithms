// https://leetcode.com/problems/majority-element/

#include <iostream>
#include <vector>
#include <unordered_map>

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.

class Solution {
public:
    int majorityElement(std::vector<int> nums) {
      auto sz = nums.size();
      std::unordered_map<int, int> m;

      for (auto &n: nums) {
        if (!m[n]) m[n] = 0;

        m[n]++;

        if (m[n] > (sz/2)) {
          return n;
        }
      }

      return 0;
    }
};


int main() {
  Solution s;
  std::cout << "s.majorityElement({1,3,1,1}) [1]: " << s.majorityElement({1,3,1,1}) << std::endl;
  std::cout << "s.majorityElement({3,4,3,4,1,4,4}) [4]: " << s.majorityElement({3,4,3,4,1,4,4}) << std::endl;
  std::cout << "s.majorityElement({1,2,3,6,6,6,6,1,6,2,6,3,6}) [6]: " << s.majorityElement({1,2,3,6,6,6,6,1,6,2,6,3,6}) << std::endl;

}
