
// header guard: preventing this file from getting copied multiple times, when it is getting used in multiple files.
// if multiple files include it (crucical to avoid redefinition errors)
#pragma once
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
    TreeNode(int data, TreeNode *left, TreeNode *right) : val(data), left(left), right(right) {};
};

TreeNode *buildTree(const std::vector<int> &nodes);
void deleteTree(TreeNode *root);
void printTree(TreeNode *root, int depth);
void preOrderPrint(TreeNode *root);
void inOrderPrint(TreeNode *root);
void postOrderPrint(TreeNode *root);