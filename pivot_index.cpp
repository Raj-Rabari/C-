#include <vector>
#include <numeric>

int pivotIndex(std::vector<int> &nums)
{
    int n = static_cast<int>(nums.size());
    int sum = 0;
    int left_sum = 0;

    // for (int i = 0; i < n; ++i)
    // {
    //     sum += nums[i];
    // }

    std::accumulate(nums.begin(), nums.end(), sum);

    for (int i = 0; i < n; ++i)
    {

        if ((left_sum) == (sum - left_sum - nums[i]))
            return i;
        left_sum += nums[i];
    }

    return -1;
}