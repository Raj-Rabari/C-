#include <iostream>
#include <vector>

int maxMoney(std::vector<int> &nums, int prev, int currHome)
{
    if (currHome >= nums.size())
    {
        return prev;
    }

    return std::max(maxMoney(nums, prev + nums[currHome], currHome + 2), maxMoney(nums, prev, currHome + 1));
}

int main()
{
    std::vector<int> arr = {114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81, 90, 222, 160, 165, 195, 187, 199, 114, 235, 197, 187, 69, 129, 64, 214, 228, 78, 188, 67, 205, 94, 205, 169, 241, 202, 144, 240};
    std::cout << maxMoney(arr, 0, 0);
}