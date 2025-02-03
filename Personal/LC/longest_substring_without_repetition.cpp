#include <iostream>
#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
    int n = s.length();
    int maxLength = 0;
    int left = 0, right = 0;
    std::unordered_set<char> uniqueChars;

    while (right < n) {
        if (uniqueChars.find(s[right]) == uniqueChars.end()) {
            uniqueChars.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
            right++;
        } else {
            uniqueChars.erase(s[left]);
            left++;
        }
    }

    return maxLength;
}

int main() {
    std::string s = "aAa";
    int result = lengthOfLongestSubstring(s);
    std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;

    return 0;
}
