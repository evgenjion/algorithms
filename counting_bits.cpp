// https://leetcode.com/problems/counting-bits/

#include <vector>
#include <iostream>

#include "helpers/pretty_print.cpp"

class Solution {
public:
    std::vector<int> countBits(int n) {
      std::vector<int> v {};
      for (int i = 0; i <= n; i++) {
        v.push_back(count(i));
      }
      return v;
    }

    int count(int n) {
      auto _count = 0;

      while (n > 1) {
        if (n % 2 == 1) _count++;

        n /= 2;
      }

      if (n == 1) _count++;

      return _count;
    }
};

int main() {
  Solution s;

  auto v1 = s.countBits(2);
  auto v2 = s.countBits(5);

  std::cout << "v1: " << v1 << std::endl;
  std::cout << "v2: " << v2 << std::endl;

  std::cout << "s.count(0): " << s.count(0) << std::endl;
  std::cout << "s.count(1): " << s.count(1) << std::endl;
  std::cout << "s.count(2): " << s.count(2) << std::endl;
  std::cout << "s.count(3): " << s.count(3) << std::endl;
  std::cout << "s.count(4): " << s.count(4) << std::endl;
  std::cout << "s.count(5): " << s.count(5) << std::endl;
}
