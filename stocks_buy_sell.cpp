// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <unordered_map>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
      return fastGoodSolution(prices);
    }

    /**
     * @brief Kadane's algorithm (dynamic programming)
     *
     * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39038/Kadane's-Algorithm-Since-no-one-has-mentioned-about-this-so-far-%3A)-(In-case-if-interviewer-twists-the-input)
     *
     */

    int kadane(std::vector<int> & prices) {
      int max = 0; int maxCur = 0;

      for (int i = 1; i < prices.size(); i++) {
        maxCur = std::max(0, maxCur += prices[i] - prices[i - 1]);
        max = std::max(max, maxCur);

        std::cout << "i: " << i << std::endl;
        std::cout << "maxCur: " << maxCur << std::endl;
      }

      return max;
    }


    /**
     * @brief https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39062/My-jave-accepted-solution-with-O(N)-time-and-O(1)-space
     *
     */
    int fastGoodSolution(std::vector<int>& prices) {
      if (prices.size() == 0) return 0;

      int max = 0; int minSoFar = prices[0];

      for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minSoFar) minSoFar = prices[i];

        max = std::max(max, prices[i]- minSoFar);
      }

      return max;
    }

    int slowBadSolution(std::vector<int>& prices) {
      int max = 0;

      for (int i = 0; i != prices.size(); i++) {
        for (int j = i; j < prices.size(); j++){
          max = std::max(max, prices[j] - prices[i]);
        }
      }

      return max;
    }
};

int main() {
  Solution s;

  std::vector v = {7,1,5,3,6,4};
  auto r = s.maxProfit(v);

  std::cout << "r: " << r << std::endl;

  auto k = s.kadane(v);

  std::cout << "k: " << k << std::endl;
}
