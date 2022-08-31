#include <cstdio>
#include <vector>
#include <algorithm> // make_heap
#include <iostream> // cin, cout
#include <string>
#include <iomanip> // setw

using std::cout;
using std::endl;
using std::cin;

void print(std::string text, std::vector<int> const &v) {
  cout << std::setw(2); // just for pretty print
  cout << text << ": ";
  for (auto n: v) cout << ' ' << n;
  cout << endl;
}

namespace my {
  typedef std::vector<int>::iterator const& Iter;

  auto comp = [](int a, int b){return a > b;}; // compare function for max heap
  auto swap = [](int &a, int &b){ int t = a; a = b; b = t; }; // swap values

  void heapify(Iter start, Iter cur, Iter finish) {
    int len = std::distance(start, finish);
    int i = std::distance(start, cur);

    int left = (i+1)*2 - 1; // because indexes starts from zero. If it was from 1 then here would be just i*2
    int right = left + 1;

    int max_p = i;// max priority

    if (left < len && comp(start[left], start[max_p]))
      max_p = left;

    if (right < len && comp(start[right], start[max_p]))
      max_p = right;

    swap(start[i], start[max_p]);

    if (left < len || right < len)
      heapify(start, start + max_p, finish);
  }

  void make_heap(Iter start, Iter finish) {
    auto half = std::distance(start, finish)/2;
    for (auto it = start + half; it >= start; it--) {
      heapify(start, it, finish);
    }
  };
}

int main() {
  std::vector <int> v  = {10, 20, 30, 40, 50, 60, 70, 80};
  // std::vector <int> v1 = {10, 30, 20, 40, 50, 60, 70, 80};
  std::vector <int> v2 = v; // copy vector

  std::make_heap(v2.begin(), v2.end());
  my::make_heap(v.begin(), v.end());
  // my::make_heap(v1.begin(), v1.end());

  print("v", v);
  // print("v1", v);
  print("v2", v2);
}
