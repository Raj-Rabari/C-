#include <iostream>
#include <vector>
#include <utility>

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};

    // you can reverse it in single optimized algorithm in production code like below using std::reverse from <algorithm> header file
    // std::reverse(arr.begin(), arr.end());

    int n = arr.size();

    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Reverse the array
    int i = 0, j = n - 1;
    while (i < j)
    {
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }

    std::cout << "Reversed array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}