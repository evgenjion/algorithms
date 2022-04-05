// https://leetcode.com/problems/climbing-stairs/

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
      return dp(n);
    }

    int dp(int n) {
      if (n <= 0) return 0;
      if (n == 1) return 1;
      if (n == 2) return 2;

      // return dp(n-1) + dp(n-2);

      // without recursion
      auto oneStepBefore = 2;
      auto twoStepBefore = 1;
      auto currentWay = 0;

      for (int i = 3; i <= n; i++) {
        currentWay = oneStepBefore + twoStepBefore;
        twoStepBefore = oneStepBefore;
        oneStepBefore = currentWay;
      }

      return currentWay;
    }

    int combination(int n) {

    }
};

int main() {
  Solution s;

  // Input: n = 3
  // Output: 3
  // Explanation: There are three ways to climb to the top.
  // 1. 1 step + 1 step + 1 step
  // 2. 1 step + 2 steps
  // 3. 2 steps + 1 step

  auto d = s.dp(5);

  std::cout << "d: " << d << std::endl;
}
