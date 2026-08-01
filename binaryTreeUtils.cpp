#include <vector>
#include "binaryTreeUtils.h"
#include <climits>
#include <queue>
#include <iostream>
#include <stack>
TreeNode *buildTree(const std::vector<int> &nodes)
{
    if (nodes.empty() || nodes[0] == INT_MIN)
        return nullptr;

    std::queue<TreeNode *> q;
    TreeNode *root = new TreeNode(nodes[0]);
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        TreeNode *currentNode = q.front();
        q.pop();

        if (nodes[i] != INT_MIN)
        {
            currentNode->left = new TreeNode(nodes[i]);
            q.push(currentNode->left);
        }

        ++i;

        if (i < nodes.size() && nodes[i] != INT_MIN)
        {
            currentNode->right = new TreeNode(nodes[i]);
            q.push(currentNode->right);
        }
        ++i;
    }
    return root;
}

void deleteTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    return;
}

// Pass depth as a default parameter for indentation
void printTree(TreeNode *root, int depth = 0)
{
    if (root == nullptr)
    {
        return;
    }

    // Go all the way right first
    printTree(root->right, depth + 1);

    // Print the current node with indentation based on its depth
    for (int i = 0; i < depth; ++i)
    {
        std::cout << "    ";
    }
    std::cout << root->val << "\n";

    // Then go left
    printTree(root->left, depth + 1);
}

void preOrderPrint(TreeNode *root)
{
    if (root == nullptr)
        return;
    std::cout << root->val << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

void inOrderPrint(TreeNode *root)
{
    if (root == nullptr)
        return;
    inOrderPrint(root->left);
    std::cout << root->val << " ";
    inOrderPrint(root->right);
}

void postOrderPrint(TreeNode *root)
{
    if (root == nullptr)
        return;
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    std::cout << root->val << " ";
}

void preOrderIterative(TreeNode *root)
{
    if (root == nullptr)
        return;

    std::stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *currNode = s.top();
        s.pop();

        std::cout << currNode->val << " ";

        if (currNode->right != nullptr)
            s.push(currNode->right);

        if (currNode->left != nullptr)
            s.push(currNode->left);
    }
}