#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int longest_repeating_character_replacement(std::string s, int k)
{
    int s = s.size();
    vector<pair<char, int> > record;
    
}

int main()
{
    std::string s = "AABABBA";
    int k = 2;
    int result = longest_repeating_character_replacement(s, k);
    std::cout << "longest_repeating_character_replacement :- " << result << std::endl;

    return 0;
}
