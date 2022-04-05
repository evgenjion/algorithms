// for tasks like https://leetcode.com/problems/symmetric-tree/

#include <vector>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(const std::vector<int> &v);
TreeNode* buildTree(const std::vector<int> &v, TreeNode* el, int currentOffset);

/**
 * @brief builds tree from std::vector to {TreeNode} and returns root element
 *
 * @param v vector of int. TODO: template?
 * @return TreeNode* root element;
 */
TreeNode* buildTree(const std::vector<int> &v) {
  auto root = new TreeNode();

  if (!v.size()) {
    return root;
  }

  buildTree(v, root, 0);

  return root;
}

TreeNode* buildTree(const std::vector<int> &v, TreeNode* el, int currentOffset) {
  auto leftIndx = (currentOffset+1)*2 - 1;
  auto rightIndx = leftIndx + 1;

  if (currentOffset >= v.size()) {
    return nullptr;
  }

  el->val = v[currentOffset];


  if (leftIndx < v.size() && (v[leftIndx] != INT_MIN)) { // INT_MIN – Костыль для  null
    el->left = new TreeNode(v[leftIndx]);
    buildTree(v, el->left, leftIndx);
  }

  if (rightIndx < v.size() && v[rightIndx] != INT_MIN) { // INT_MIN – Костыль для  null
    el->right = new TreeNode(v[rightIndx]);
    buildTree(v, el->right, rightIndx);
  }

  return el;
}
