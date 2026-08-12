#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> arr = {1, 3, 5, 6};
    int target = 2;

    int left = 0;
    int right = arr.size();

    auto it = std::lower_bound(arr.begin(), arr.end(), target);

    std::cout << std::distance(arr.begin(), it);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            std::cout << mid << std::endl;
            break;
        }
    }

    std::cout << "left: " << left << std::endl;
}