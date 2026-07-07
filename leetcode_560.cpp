#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySum(std::vector<int> &nums, int k)
{
    int count = 0;
    int n = static_cast<int>(nums.size());
    std::unordered_map<int, int> prefix_sum_count = {
        {0, 1}};
    int prefix_sum = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        prefix_sum += nums[i];
        int remainder = prefix_sum - k;

        if (prefix_sum_count.find(remainder) != prefix_sum_count.end())
        {
            ans += prefix_sum_count[remainder];
        }

        prefix_sum_count[prefix_sum]++;
    }
    return ans;
}

int main()
{
    std::vector<int> nums = {1, -1, 0};
    int k = 0;

    std::cout << "Number of subarrays with sum " << k << ": " << subarraySum(nums, k) << std::endl;

    return 0;
}