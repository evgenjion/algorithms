// https://leetcode.com/problems/longest-common-subsequence/
#include <string>
#include <iostream>
#include <utility>
#include <vector>


class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
      auto H_SIZE = text1.size() + 1;
      auto V_SIZE = text2.size() + 1;

      int** m = new int*[H_SIZE];
      for (int i = 0; i < H_SIZE; i++) {
        m[i] = new int[V_SIZE + 1]();
        // m[i] = { 0 };
      }

      for (int i = 0; i < text1.size(); i++) {
        for (int j = 0; j < text2.size(); j++) {
          if (text1[i] == text2[j]) {
            m[i+1][j+1] = m[i][j] + 1;
          } else {
            m[i+1][j+1] = std::max(m[i+1][j], m[i][j+1]);
          }
        }
      }

      return m[text1.size()][text2.size()];
    }
};

class MyBadSolution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
      std::vector< std::pair<int, int> > r;

      for (int i = 0; i < text1.size(); ++i) {
        r.push_back(std::make_pair(0, 0));
        int idx = 0;

        for (int j = i; j < text1.size(); ++j) {
          // int count = 0;

          for (int k = idx; k < text2.size(); ++k) {
            if (text1[j] == text2[k]) {
              // count++;
              r.back().first++;

              idx = k + 1;
              break;
            }
          }
        }

        if (i != 0) {
          r.back().second = std::max(r.back().first, r[i-1].second);
        } else {
          r.back().second = r.back().first;
        }
      }

      return r.back().second;
    }
};

int main() {
  Solution s;
  // s.longestCommonSubsequence("bl", "yby"); // DONE
  // s.longestCommonSubsequence("ezupkr", "ubmrapg"); // DONE
  // s.longestCommonSubsequence("oxcpqrsvwf", "shmtulqrypy"); // DONE

  s.longestCommonSubsequence("ace", "abcde"); // DONE
  // s.longestCommonSubsequence("abcde", "ace"); // DONE
  s.longestCommonSubsequence("mhunuzqrkzsnidwbun", "szulspmhwpazoxijwbq");
}
