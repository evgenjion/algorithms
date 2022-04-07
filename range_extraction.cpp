#include <vector>
#include <string>
#include <iostream>

std::string range_extraction(std::vector<int> const &v) {
  std::string s = "";

  int i = 0;
  auto size = v.size();

  while (i < size) {
    int j = i;

    while (j < size - 1) {
      if ((v[j] + 1) == v[j+1]) {
        j++;
      } else {
        break;
      }
    }

    if (i == j) {
      s += std::to_string(v[i]);
    } else if ((j - i) == 1) {
      s += std::to_string(v[i]) + ',' + std::to_string(v[j]);
      i = j + 1;
    } else {
      s += std::to_string(v[i]) + '-' + std::to_string(v[j]);
      i = j + 1;
    }

    if (j != size - 1) {
      s += ',';
    }

    if (j == v.size() - 1) break;

    if (i == j) i++;
  }

  return s;
}

std::string range_extraction_NOT_WORKING(std::vector<int> const &v) {
  std::string s = "";
  // auto first = true;
  auto startPos = 0;
  auto endPos = startPos;
  auto continues = 0;

  for (int i = 1; i < v.size(); i++) {
    if ((v[i] - v[i-1]) == 1) {
      continues++;
    } else {
      // TODO: continues в другое место?
      continues = 0;
    }

    if (continues > 0) {
      endPos = i;

      if (i != v.size() - 1) {
        continue;
      }
    }

    std::cout << "continues: " << continues << std::endl;

    if (continues == 1) {
      std::cout << "continues: " << continues << std::endl;
      std::cout << "v[startPos]: " << v[startPos] << std::endl;
      std::cout << "v[endPos]: " << v[endPos] << std::endl;
    }

    if (continues == 1) endPos = startPos;

    if (endPos == startPos) {
      s += std::to_string(v[startPos]);
      startPos++;
      endPos++;
    } else {
      s += std::to_string(v[startPos]) + "-" + std::to_string(v[endPos]);
      startPos = endPos + 1;
      endPos = startPos;
    }

    if (i != v.size() - 1) {
      s += ',';
    }
  }

  return s;
}

int main() {
  auto t = range_extraction({-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20});
  // / returns "-6,-3-1,3-5,7-11,14,15,17-20"

  std::cout << "t: " << t << std::endl;
}



// Из интернетов прикольное решение:
std::string range_extraction(std::vector<int> args)
{
    using Range = std::pair<int, int>;
    std::vector<Range> ranges;
    for(auto &i : args)
        if(ranges.empty() || ranges.back().second + 1 != i)
            ranges.push_back({i, i});
        else
            ++ranges.back().second;

    std::string result;
    for(auto &r : ranges)
        if(r.first == r.second)
            result.append(std::to_string(r.first) + ",");
        else
            result.append(std::to_string(r.first) +
                          ((r.first + 1 == r.second) ? ',' : '-') +
                          std::to_string(r.second) +
                          ",");
    result.pop_back();
    return result;
}
