#pragma once

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

TreeNode* buildTree(const std::vector<int> &v);
TreeNode* buildTree(const std::vector<int> &v, TreeNode* el, int currentOffset);
