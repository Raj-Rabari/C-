#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int left = i + 1;
        int right = static_cast<int>(nums.size()) - 1;
        int curr_num = nums[i];

        while (left < right)
        {
            int sum = curr_num + nums[left] + nums[right];
            if (sum == 0)
            {
                ans.push_back({curr_num, nums[left], nums[right]});
                ++left;
                --right;
            }
            else if (sum > 0)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }
    }
    return ans;
}

int main()
{
    std::vector<int> input_arr = {1, 2, 0, 1, 0, 0, 0, 0};

    std::vector<std::vector<int>> ans = threeSum(input_arr);
    std::cout << "done: " << std::endl;
    return 0;
}