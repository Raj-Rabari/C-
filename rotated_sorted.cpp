#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums = {3, 4, 5, 1, 2};
    int left = 0;
    int right = static_cast<int>(nums.size() - 1);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= nums[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    std::cout << nums[right];
}