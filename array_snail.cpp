// https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1/train/cpp

#include <iostream>
#include <vector>

void print_vector(std::vector<std::vector<int>> const &v) {
  // std::distance
  for (auto i = v.begin(); i < v.end(); i++) {
    for (auto j = i->begin(); j < i->end(); j++) {
      std::cout << *j << " ";
      // std::cout <<
      //   "v[" << std::distance(v.begin(), i)
      //   << "][" << std::distance(i->begin(), j) << "]: "
      //   << *j
      //   << std::endl;
    }
    std::cout << std::endl;
  }

}

void print_vector(std::vector<int> const &v) {
  for (auto &&c: v) {
    std::cout << c << " ";
  }

  std::cout << std::endl;
}

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  // snail_map = [[1,2,3],
  //        [4,5,6],
  //        [7,8,9]]
  std::vector<int> result = {};

  int topBorder = 0;
  int bottomBorder = snail_map.size() - 1;
  int leftBorder = 0;
  int rightBorder = snail_map[0].size() - 1;

  short const RIGHT = 0;
  short const BOTTOM = 1;
  short const LEFT = 2;
  short const TOP = 3;

  short direction = RIGHT;

  int h = leftBorder;
  int v = topBorder;

  while (topBorder <= bottomBorder && leftBorder <= rightBorder) {
    // std::cout << "---------: " << std::endl;
    // std::cout << "v: " << v << std::endl;
    // std::cout << "h: " << h << std::endl;
    // std::cout << "topBorder: " << topBorder << std::endl;
    // std::cout << "bottomBorder: " << bottomBorder << std::endl;
    // std::cout << "leftBorder: " << leftBorder << std::endl;
    // std::cout << "rightBorder: " << rightBorder << std::endl;
    // std::cout << "direction: " << direction << std::endl;

    result.push_back(snail_map[v][h]); // visit

    if (direction == RIGHT) {
      if (h == rightBorder) {
        direction = BOTTOM;
        topBorder++;
        v++;
        continue;
      }

      h++;
    }
    else if (direction == BOTTOM) {
      if (v == bottomBorder) {
        direction = LEFT;
        rightBorder--;
        h--;

        continue;
      }

      v++;
    }
    else if (direction == LEFT) {
      if (h == leftBorder) {
        direction = TOP;
        bottomBorder--;
        v--;

        continue;
      }

      h--;
    }
    else if (direction == TOP) {
      if (v == topBorder) {
        direction = RIGHT;
        leftBorder++;
        h++;

        continue;
      }

      v--;
    }
  }

  return result;
}


int main() {
  // TODO: give snail
  std::vector<std::vector<int>> v_snail = {
    {1, 2, 3},
    {8, 9, 4},
    {7, 6, 5}
  };

  // print_vector(snail);
  auto v = snail(v_snail);

  print_vector(v);
}



// Решение из интернетов:
std::vector<int> snail_ETALON(const std::vector<std::vector<int>>& xs) {
  std::vector<int> res;
  if (xs[0].empty())
    return res;
  const std::size_t ny = xs.size(), nx = xs[0].size();
  res.reserve(ny * nx);
  std::ptrdiff_t x0 = 0, y0 = 0, x1 = nx - 1, y1 = ny - 1, x = 0, y = 0;
  while (y0 <= y1) {
    while (x < x1) res.push_back(xs[y][x++]); y0++;
    while (y < y1) res.push_back(xs[y++][x]); x1--;
    while (x > x0) res.push_back(xs[y][x--]); y1--;
    while (y > y0) res.push_back(xs[y--][x]); x0++;
  }
  res.push_back(xs[y][x]);
  return res;
}
