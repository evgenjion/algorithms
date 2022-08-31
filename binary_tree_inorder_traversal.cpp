// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

#include <vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

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
    std::vector <int> v;
    std::vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return v;

        auto l = root->left;
        auto r = root->right;

        if (l != nullptr) inorderTraversal(l);
        v.push_back(root->val);
        if (r != nullptr) inorderTraversal(r);

        return v;
    }
};
