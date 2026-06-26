#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    std::vector<int> arr = {2, 7, 11, 15, 27};

    int target = 9;

    std::unordered_map<int, int> num_map;

    for (int i = 0; i < arr.size(); ++i)
    {
        int complement = target - arr[i];

        if (num_map.find(complement) != num_map.end())
        {
            std::cout << "Indices: " << num_map[complement] << ", " << i << std::endl;
            break;
        }
        num_map[arr[i]] = i;
    }

    return 0;
}