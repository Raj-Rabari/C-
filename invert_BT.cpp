// recursive version submitted on leetcode 226, here i am writing iterative version

#include <iostream>
#include <queue>
#include <climits>
#include "binaryTreeUtils.h"

TreeNode *invertBT(TreeNode *root)
{
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *currentNode = q.front();
        q.pop();

        std::swap(currentNode->left, currentNode->right);
        if (currentNode->left != nullptr)
            q.push(currentNode->left);
        if (currentNode->left != nullptr)
            q.push(currentNode->right);
    }

    return root;
}

int main()
{
    std::vector<int> nodes = {3, 1, 5, 4, 6, 7, 8};
    TreeNode *root = buildTree(nodes);
    printTree(invertBT(root), 0);
}