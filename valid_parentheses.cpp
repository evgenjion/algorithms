#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
      std::vector<char> stack;
      std::unordered_map<char, char> m = {
        {'}', '{'},
        {']', '['},
        {')', '('}
      };
      auto is_open = [](const char &c){ return c == '{' || c == '[' || c == '('; };

      for (const auto &c: s) {
        if (is_open(c)){
          stack.push_back(c);
          continue;
        }

        if (stack.empty()) {
          return false;
        }

        if (stack.back() == m[c]) {
          stack.pop_back();
        } else {
          return false;
        }
      }

      return true;
    }
};

int main() {
  auto s = new Solution();

  std::cout << "s->isValid(\"()[{()}]{}\"): " << s->isValid("()[{()}]{}") << std::endl;
  std::cout << "s->isValid(\"()[{()}]{}\"): " << s->isValid("()[{(])}]{}") << std::endl;

}
