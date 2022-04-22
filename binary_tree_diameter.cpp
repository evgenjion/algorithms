#include <iostream>
#include <vector>
#include <queue>

#include "helpers/build_tree_from_array.cpp"
#include "helpers/pretty_print.cpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int ans = -INT_MAX;
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if (!root) return 0;

      recursiveSolution(root);

      return ans;
    }

    int recursiveSolution(TreeNode* root) {
      if (root == nullptr) return 0;

      auto l = recursiveSolution(root->left);
      auto r = recursiveSolution(root->right);

      ans = std::max(ans, l + r);
      return std::max(l, r) + 1;

      // auto d = depth(root->left) + depth(root->right);

      // return std::max({ recursiveSolution(root->left), recursiveSolution(root->right) }) + 1;
    }

    // BFS wrong way
    int depth(TreeNode* root) {
      if (root == nullptr) return 0;

      std::queue<TreeNode*> q;
      int d = 0;

      q.push(root);

      while (!q.empty()) {
        d++;

        for (int i = 0; i < q.size(); ++i) {
          auto cur = q.front();

          if (cur->left) q.push(cur->left);
          if (cur->right) q.push(cur->right);

          q.pop();
        }
      }

      return d;
    }
};

int main() {
  std::vector<int> v = { 1, 2, 3, 4, 5 };
  std::vector<int> v1 = {5,0,-4,-1,-6,-9,INT_MIN,7,INT_MIN,1,3,INT_MIN,0,INT_MIN,9,INT_MIN,INT_MIN,6,0,INT_MIN,-7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,-4,INT_MIN,1,INT_MIN,INT_MIN,-4};

  auto t = buildTree(v);
  auto t1 = buildTree(v1);

  Solution s;

  std::cout << "s.depth(t): " << s.depth(t) << std::endl;
  auto r = s.diameterOfBinaryTree(t);
  std::cout << "r: " << r << std::endl;

  // auto r1 = s.diameterOfBinaryTree(t1);
  // std::cout << "r1: " << r1 << std::endl;

  // std::cout << "s.depth(t1): " << s.depth(t1) << std::endl;
  // std::cout << "s.depth(t1->left): " << s.depth(t1->left) << std::endl;
  // std::cout << "s.depth(t1->right): " << s.depth(t1->right) << std::endl;
}
