#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int n = static_cast<int>(nums.size());
    int min_length = INT_MAX;
    int left = 0, sum = 0;

    for (int right = 0; right < n; ++right)
    {
        sum += nums[right];

        while (sum >= target)
        {
            min_length = std::min(min_length, right - left + 1);
            sum -= nums[left];
            ++left;
        }
    }

    return min_length != INT_MAX ? min_length : 0;
}
int main()
{
    std::vector<int> input_arr = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int ans = minSubArrayLen(target, input_arr);
    std::cout << "done: " << ans << std::endl;
    return 0;
}