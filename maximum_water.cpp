#include <iostream>
#include <vector>
#include <algorithm>

int maxWater(const std::vector<int> &height)
{
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    int max_water = 0;

    while (left < right)
    {
        int current_left = height[left];
        int current_right = height[right];

        int area = std::min(current_left, current_right) * (right - left);
        max_water = std::max(max_water, area);

        if (current_left < current_right)
        {
            while (left < right && current_left >= height[left])
            {
                ++left;
            }
        }
        else
        {
            while (left < right && current_right >= height[right])
            {
                --right;
            }
        }
    }
    return max_water;
}