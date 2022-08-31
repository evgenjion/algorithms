#include <string>
#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;

// rgb(255, 255, 255) # returns FFFFFF
// rgb(255, 255, 300) # returns FFFFFF
// rgb(0,0,0) # returns 000000
// rgb(148, 0, 211) # returns 9400D3

std::unordered_map<int, char> m = {
  {0, '0'},
  {1, '1'},
  {2, '2'},
  {3, '3'},
  {4, '4'},
  {5, '5'},
  {6, '6'},
  {7, '7'},
  {8, '8'},
  {9, '9'},
  {10, 'A'},
  {11, 'B'},
  {12, 'C'},
  {13, 'D'},
  {14, 'E'},
  {15, 'F'}
};

std::string rgb(int r, int g, int b) {
  auto convert = [](int &c) {
    if (c >= 255) return std::string("FF");
    if (c <= 0) return std::string("00");

    std::string hex = "";

    // stolen from internet :'(
    do {
      hex = m[c % 16] + hex;
      c /= 16; // for example 15 / 16 == 0. thats why (integer division https://stackoverflow.com/questions/3602827/what-is-the-behavior-of-integer-division)
    } while (c != 0);

    while (hex.size() < 2) {
      hex = "0" + hex;
    }

    return hex;
  };

  return convert(r) + convert(g) + convert(b);
};

int main() {
  std::cout << "rgb(255, 255, 255): " << rgb(255, 255, 255) << std::endl;
  std::cout << "rgb(255, 255, 300): " << rgb(255, 255, 300) << std::endl;
  std::cout << "rgb(0, 0, 0): " << rgb(0, 0, 0) << std::endl;
  std::cout << "rgb(148, 0, 211): " << rgb(148, 0, 211) << std::endl;


  std::cout << "rgb(-20, 275, 125): " << rgb(-20, 275, 125) << std::endl;

}
