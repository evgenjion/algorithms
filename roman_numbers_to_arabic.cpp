#include <iostream>
#include <string>
#include <unordered_map>

int roman_to_arabic(std::string roman) {
  std::unordered_map<char, int> values_map = {
    {'I',    1 },
    {'V',    5 },
    {'X',   10 },
    {'L',   50 },
    {'C',  100 },
    {'D',  500 },
    {'M', 1000 }
  };

  auto base_index = roman.size() - 1;
  auto base_value = values_map[roman[base_index]]; // last number
  int res = 0;

  for (int i = roman.size(); i >= 0; i--) {
    const auto &current_char = roman[i];
    const auto &value = values_map[current_char]; // current value

    if (value >= base_value) {
      res += value;
      base_index = i;
      base_value = value;
    } else {
      res -= value;
    }
  }

  return res;
}

int main() {
  std::cout << roman_to_arabic("VIII") << std::endl; // 8
  std::cout << roman_to_arabic("XIX") << std::endl; // 19
  std::cout << roman_to_arabic("XXI") << std::endl; // 21
  std::cout << roman_to_arabic("MCMXC") << std::endl; // 1990
}
