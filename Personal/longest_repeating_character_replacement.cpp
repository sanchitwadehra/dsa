#include <iostream>
#include <string>
#include <unordered_set>

int longest_repeating_character_replacement(std::string s,int k) {
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
    std::string s = "AABABBA";
    int k = 1;
    int result = longest_repeating_character_replacement(s,k);
    std::cout << "longest_repeating_character_replacement :- " << result << std::endl;

    return 0;
}
