#include <iostream>
#include <vector>

using std::cout;
using std::endl;


void print_matrix (const std::vector<std::vector<int>> &m, const std::string &name) {
  cout << "printing " << name << ": " << endl;

  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[0].size(); j++) {
      cout << m[i][j] << ' ';
    }
    cout << endl;
  }
}

std::vector<std::vector<int>> rotate_clockwise(const std::vector<std::vector<int>> &m) {
  auto h = m.size();
  auto w = m[0].size();

  std::vector<std::vector<int>> r;
  r.reserve(w);

  for (int i = 0; i < w; i++) {
    // r[i] = {};
    r.push_back({});
    r[i].reserve(h);

    for (int j = 0; j < h; j++) {
      // r[i][j] = m[h - j - 1][i];
      r[i].push_back(m[h - j - 1][i]);
    }
  }

  return r;
}

std::vector<std::vector<int>> rotate_counterclock(const std::vector<std::vector<int>> &m) {
  auto h = m.size();
  auto w = m[0].size();

  std::vector<std::vector<int>> r;
  r.reserve(w);

  for (int i = 0; i < w; i++) {
    r.push_back({});

    for (int j = 0; j < h; j++) {
      r[i].push_back(m[j][w - i - 1]);
    }
  }

  return r;
}


int main() {
  std::vector<std::vector<int>> m = {
    {1,2,3},
    {4,5,6}
  };

  auto &&r = rotate_clockwise(m);

  print_matrix(m, "m");

  cout << "---------------------" << endl;

  print_matrix(r, "[rotated clockwise]");

  auto && c =  rotate_counterclock(m);

  cout << "---------------------" << endl;

  print_matrix(c, "[rotated counterclock]");
}
