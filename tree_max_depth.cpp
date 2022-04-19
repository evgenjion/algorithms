#include "helpers/build_tree_from_array.cpp"

#include <cmath>
#include <deque>
#include <queue>

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
public:
    int maxDepth(TreeNode* root) {
      return recursive(root);
    }

    /**
     * @brief DFS
     */
    int recursive(TreeNode* root) {
      if (root == NULL) return 0;

      return 1 + std::max(recursive(root->left), recursive(root->right));
    }

    /**
     * @brief BFS
     */
    int iterative(TreeNode* root) {
      std::queue<TreeNode*> q;
      q.push(root);

      int depth = 0;

      while (q.size() > 0) {
        depth++;

        for (int i = 0; i < q.size(); i++) {
          auto t = q.front();
          q.pop();

          if (t->left != NULL)
            q.push(t->left);
          if (t->right != NULL)
            q.push(t->right);
        }
      }

      return depth;
    }

    /**
     * @brief Старый вариант. С лишней очередью
     *
     */
    int iterative_old(TreeNode* root) {
      std::deque<TreeNode*> q;
      q.push_back(root);

      int depth = 0;

      while (q.size() > 0) {
        std::queue<TreeNode*> level = {};

        for (auto &&t: q) {
          if (t->left != NULL) {
            level.push(t->left);
          }

          if (t->right != NULL) {
            level.push(t->right);
          }
        }

        while (q.size() > 0) {
          q.pop_back();
        }
        depth++;

        while (level.size() > 0) {
          q.push_back(level.front());
          level.pop();
        }
      }

      return depth;
    }
};

int main() {
  Solution s;

  auto t = buildTree({3,9,20,INT_MIN,INT_MIN,15,7});
  auto iter = s.iterative(t);
  auto rec = s.recursive(t);

  std::cout << "iter: " << iter << std::endl;
  std::cout << "rec: " << rec << std::endl;
}
