#include <iostream>
#include <vector>
#include <climits>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : left(nullptr), right(nullptr), val(x) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : left(left), right(right), val(x) {};
    TreeNode() : left(nullptr), right(nullptr), val(0) {};
};

TreeNode *buildTree(const std::vector<int> &nodes)
{
    if (nodes.empty() || nodes[0] == INT_MIN)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    std::queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (nodes[i] != INT_MIN)
        {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        ++i;

        if (i < nodes.size() && nodes[i] != INT_MIN)
        {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        ++i;
    }
    return root;
}

void deleteTree(TreeNode *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    return;
}

int maxDepthBFS(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    std::queue<TreeNode *> q;
    q.push(root);
    int depth = 0;

    while (!q.empty())
    {
        int levelSize = q.size();
        ++depth;

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *current = q.front();
            q.pop();

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
    return depth;
}

int main()
{
    std::vector<int> tree = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root = buildTree(tree);
    std::cout << "maximum depth of tree is: " << maxDepthBFS(root) << std::endl;
    return 0;
}