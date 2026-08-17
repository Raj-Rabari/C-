#include <iostream>
#include <vector>

int getMax(const std::vector<int> &nums, int start, int end)
{
    int prev1 = 0;
    int prev2 = 0;

    for (int i = start; i <= end; ++i)
    {
        int current_max = std::max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current_max;
    }

    return prev1;
}

int main()
{
    std::vector<int> nums = {2, 3, 2};
    int n = static_cast<int>(nums.size());
    std::cout << std::max(getMax(nums, 1, n - 1), getMax(nums, 0, n - 2)) << std::endl;
}