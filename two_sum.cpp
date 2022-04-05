// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <unordered_map>

// using namespace std;
using std::cout;

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      std::unordered_map<int, int> m; // n, index

      for (auto it = nums.begin(); it != nums.end(); it++) {
        int indx = std::distance(nums.begin(), it);
        int diff = target - *it;

        if (m.count(diff)) {
          return {m[diff], indx};
        }

        m[*it] = indx;
      }

      return {};
    }
};

int main() {
  std::vector<int> nums = {2,7,11,15}; // 0, 1
  int target = 9;

  auto t = (new Solution())->twoSum(nums, target);
  cout << "[ ";
  for (auto &&n : t) {
    cout << n << ' ';
  }
  cout << " ]";
}
