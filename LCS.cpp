#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
    std::vector<int> arr = {100, 4, 200, 1, 3, 2};
    int ans = 0;
    int curr_count = 0;
    std::unordered_set<int> nums_set;

    for (const int &num : arr)
    {
        nums_set.insert(num);
    }

    for (const int &num : nums_set)
    {
        if (nums_set.find(num - 1) != nums_set.end())
        {
            ++curr_count;
        }
        else
        {
            ans = curr_count > ans ? curr_count : ans;
            curr_count = 0;
        }
    }

    return curr_count > ans ? curr_count : ans;
}