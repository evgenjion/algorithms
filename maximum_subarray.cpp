// https://leetcode.com/problems/maximum-subarray/

// @see explanations: https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

#include <chrono>
#include <string>

// https://www.youtube.com/watch?v=oEx5vGNFrLk

struct Timer
{
  std::chrono::time_point<std::chrono::steady_clock> start, end;
  std::chrono::duration<float> duration;
  const std::string mark;

  Timer(): mark("undef") {
    start = std::chrono::high_resolution_clock::now();
  }

  Timer(const std::string &m): mark(m) {
    // this.mark = mark;
    start = std::chrono::high_resolution_clock::now();
  }

  ~Timer() {
    start = std::chrono::high_resolution_clock::now();
    duration = end - start;

    float ms = duration.count() * 1000.0f;
    std::cout << '[' << mark << "] " << "took " << ms << "ms" << std::endl;
  }
};

class Solution {
public:
    // Kadane's algorithm.
    int kadane(const std::vector<int>& nums) {
      Timer timer("Kadane");
      int current_sum = 0; // lower than minimum num in constraints
      int max_sum = INT_MIN;

      for (const auto &n: nums) {
        current_sum = std::max(n, n + current_sum);
        max_sum = std::max(max_sum, current_sum);
      }

      return max_sum;
    }

    int iterative(const std::vector<int>& nums) {
      Timer timer("Iterative");
      std::vector<std::vector<int>> c(2, std::vector<int>(nums.size(), -1));

      c[0][0] = c[1][0] = nums[0];

      for (auto i = 1; i < nums.size(); i++) {
        c[1][i] = std::max(nums[i], nums[i] + c[1][i-1]);
        c[0][i] = std::max(c[1][i], c[0][i-1]);
      }

      return c[0].back();
    }

    int divide_conquer_opt(const std::vector<int>& nums) {
      Timer timer("divide_conquer_optimized");
      std::vector<int> pre, suf; // maximum prefix and suffix
      pre = suf = nums; // just clone

      for (int i = 1; i < nums.size(); i++) {
        pre[i] += std::max(0, pre[i - 1]);
      }

      for (int i = nums.size() - 2; i >= 0; i--) {
        suf[i] += std::max(0, suf[i + 1]);
      }

      return divide_conquer_opt(nums, 0, nums.size() - 1, pre, suf);
    }

    int divide_conquer_opt(
      const std::vector<int>& nums,
      int L,
      int R,
      const std::vector<int>& pre,
      const std::vector<int>& suf) {
      if (L == R) return nums[L];

      int mid = (L + R) / 2;

      return std::max({
        divide_conquer_opt(nums,    L,  mid, pre, suf),
        divide_conquer_opt(nums, mid + 1, R, pre, suf),
        pre[mid] + suf[mid + 1]
      });
    }

    int divide_conquer_unoptimized(const std::vector<int>& nums) {
      Timer timer("divide_conquer_unoptimized");
      return divide_conquer_unoptimized(nums, 0, nums.size() - 1);
    }

    int divide_conquer_unoptimized(const std::vector<int>& nums, int L, int R) {

      if (L > R) {
        return INT_MIN;
      }

      int mid = (L + R) / 2;
      int left_sum = 0, right_sum = 0;

      // left_sum = max subarray sum in [L, mid-1] and starting from mid-1
      for (int i = mid - 1, cur = 0; i >= L; i--) {
        cur += nums[i];
        left_sum = std::max(cur, left_sum);
      }

      for (int i = mid + 1, cur = 0; i <= R; i++) {
        cur += nums[i];
        right_sum = std::max(cur, right_sum);
      }


      return std::max({
        divide_conquer_unoptimized(nums, L, mid -1),
        divide_conquer_unoptimized(nums, mid + 1, R),
        left_sum + nums[mid] + right_sum
      });
    }

    int recursive(const std::vector<int>& nums) {
      Timer timer("recursive");
      std::vector<std::vector<int>> dp(2, std::vector<int>(size(nums), -1));
      return solve_recursive(nums, 0, false, dp);
    }
private:
  int solve_recursive(
    const std::vector<int>& nums,
    int i,
    bool mustPick,
    std::vector<std::vector<int>> &dp
  ) {
    if (i >= nums.size()) {
      return mustPick ?
        0 :
        INT_MIN;
    }

    if(dp[mustPick][i] != -1) return dp[mustPick][i];

    if (mustPick) { // right tree
      return dp[mustPick][i] = std::max(0, nums[i] + solve_recursive(nums, i+1, true, dp));
    } else { // left tree
      return dp[mustPick][i] = std::max(
        solve_recursive(nums, i+1, false, dp),
        nums[i] + solve_recursive(nums, i+1, true, dp)
      );
    }
  }
};

int main() {
  Solution s;
  std::vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};

  std::cout << "nums.size(): " << nums.size() << "\n";

  auto k = s.kadane(nums);
  auto iter = s.iterative(nums);
  auto r = s.recursive(nums);
  auto dcu = s.divide_conquer_unoptimized(nums);
  auto dco = s.divide_conquer_opt(nums);

  std::cout << "Should be: " << 6 << std::endl;
  std::cout << "k: " << k << std::endl;
  std::cout << "iter: " << iter << std::endl;
  std::cout << "r: " << r << std::endl;
  std::cout << "dcu: " << dcu << std::endl;
  std::cout << "dco: " << dco << std::endl;
}
