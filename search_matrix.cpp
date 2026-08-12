#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;
    int left = 0;
    int m = static_cast<int>(matrix.size());
    int n = static_cast<int>(matrix[0].size());
    int row = 0;
    int right = n - 1;

    while (row < m || left <= right)
    {
        if (left > right)
        {
            row++;
            left = 0;
            right = n - 1;
            continue;
        }
        int mid = left + (right - left) / 2;
        if (matrix[row][mid] > target)
        {
            right = mid - 1;
        }
        else if (matrix[row][mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            std::cout << true << std::endl;
        }
    }
    std::cout << false << std::endl;
    return 0;
}