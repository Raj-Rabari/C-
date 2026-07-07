#include <iostream>
#include <vector>
#include <string>

int lengthOfLongestSubstring(std::string s)
{
    std::vector<bool> chars(128, false);
    int n = static_cast<int>(s.length());
    int left = 0;
    int ans = 0;

    for (int right = 0; right < n; right++)
    {
        while (chars[s[right]])
        {
            chars[s[left]] = false;
            left++;
        }
        chars[s[right]] = true;
        ans = std::max(ans, right - left + 1);
    }

    return ans;
}