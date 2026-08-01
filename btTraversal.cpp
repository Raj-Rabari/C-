#include <iostream>
#include "binaryTreeUtils.h"
#include <vector>
#include <climits>

int main()
{
    std::vector<int> nodes = {10, 5, 15, INT_MIN, INT_MIN, 6, 20};
    TreeNode *root = buildTree(nodes);
    inOrderPrint(root);
    std::cout << std::endl;
    return 0;
}