// Так плохо. Надо инклудить hpp файлы и компилить через:
// clang++ -std=c++17 symmetric_tree.cpp helpers/build_tree_from_array.cpp
// Причина – масштабирование.
#include "helpers/build_tree_from_array.cpp"

#include <vector>
#include <iostream>

class Solution {
  public:
    bool is_symmetric(TreeNode *node) {
      auto left = node->left;
      auto right = node->right;

      return is_symmetric(left, right);
    }

    bool is_symmetric(TreeNode *left, TreeNode *right) {
      if (left == nullptr && right == nullptr) {
        return true;
      }

      // Можно упростить до if (left == nullptr || right == nullptr). Оставил как было изначально
      if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr)) {
        return false;
      }

      if (left->val != right->val) {
        return false;
      }

      return is_symmetric(left->left, right->right) && is_symmetric(left->right, right->left);
    }

    /**
     * @brief ITERATIVE FROM LEETCODE
     */
    bool isSymmetric(TreeNode* root) {
        TreeNode *left, *right;
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()) {
            left=q.front();
            q.pop();
            right=q.front();
            q.pop();
            if(left==NULL && right==NULL)
                continue;
            if(left==NULL || right==NULL)
                return false;
            if(left->val!=right->val)
                return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }












    bool is_equal(TreeNode *node) {
      auto left = node->left;
      auto right = node->right;

      return is_equal(left, right);
    }

    bool is_equal(TreeNode *left, TreeNode *right) {
      if (left != nullptr)
        std::cout << "left->val: " << left->val << std::endl;
      if (right != nullptr)
        std::cout << "right->val: " << right->val << std::endl;

      if (left == nullptr && right == nullptr) {
        return true;
      }

      if ((left == nullptr && right != nullptr) || (right == nullptr && left != nullptr)) {
        return false;
      }

      if (left->val != right->val) {
        return false;
      }

      return is_equal(left->left, right->left) && is_equal(left->right, right->right);
    }
};

int main() {
  // std::vector treeArr1 = {1,2,2,3,4,3,4};
  // std::vector treeArr = { 1, 2, 2, 3, 4, 3, 4, 5, 0, 6, 0, 5, 0, 6, 0};
  //                         1     3     5     7     9            ,  , 15
  //                         2     4     6     8    10          14,  , 16

  // true
  std::vector symmetricTree1 = {1,2,2,3,4,4,3};
  std::vector symmetricTree2 = {1,2,2,INT_MIN,3,INT_MIN,3};
  // false
  // [1,2,2,null,3,null,3]
  // auto root = buildTree(treeArr);

  Solution s;
  auto result = s.is_symmetric(buildTree(symmetricTree1));

  std::cout << "result1 (should be 1): " << result << std::endl;
  std::cout << "result2 (should be 0): " << s.is_symmetric(buildTree(symmetricTree2)) << std::endl;

  // auto result2 = s.is_simmetric(buildTree(treeArr1));
  // std::cout << "result2: " << result2 << std::endl;

  // std::cout << "root->val: " << root->val << std::endl;
  // std::cout << "root->left->left->val: " << root->left->left->val << std::endl;
  // std::cout << "root->left->left->val: " << root->left->left->left->val << std::endl; // 5
  // std::cout << "root->left->left->val: " << root->left->right->left->val << std::endl; // 6

  // std::cout << "root->left->left->val: " << root->left->right->left->val << std::endl; // 6

}
