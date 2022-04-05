//27 min

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::cout;
using std::cin;
using std::endl;

bool is_valid(std::string &&s) {
  auto is_open_bracket = [](char c){ return c == '(' || c == '[' || c == '{'; };

  std::vector<char> stack {};

  std::unordered_map<char, char> brackets = {
    {'}', '{'},
    {')', '('},
    {']', '['}
  };


  for (auto&& c: s) {
    if (is_open_bracket(c))
      stack.push_back(c);
    else // c one of '}' ']' ')'
      if (stack.empty()) {
        return false;
      }
      else {
        auto&& bracket = stack.back();
        stack.pop_back();

        if (brackets[c] != bracket)
          return false;
      }

  }

  return true;
}

int main() {
  cout << is_valid("()") << endl; // true
  cout << is_valid("(){}") << endl; // true
  cout << is_valid("([]{}([{}]))") << endl; // true
  cout << is_valid("(){}[{)()}]") << endl; // false
}
