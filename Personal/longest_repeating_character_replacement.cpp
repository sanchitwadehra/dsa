#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longest_repeating_character_replacement(string s, int k)
{
    unordered_map<char, int> record;
    int l, r, g;
    g = 0;
    l = 0;
    r = 0;
    char top_element;
    int temp_k, check_k;

    auto compare = [](const auto &lhs, const auto &rhs)
    {
        return lhs.second < rhs.second;
    };

    record[s[l]]++;

    while (r < s.length())
    {
        auto it = max_element(record.begin(), record.end(), compare);
        top_element = it->first;
        temp_k = (r - l + 1) - record[top_element];

        if ((r - l + 1) > g)
        {
            g = (r - l + 1);
        }

        if ((r + 1) >= s.length())
        {
            break;
        }

        if (s[r + 1] == top_element)
        {
            check_k = temp_k;
        }
        else
        {
            check_k = temp_k + 1;
        }

        if (check_k > k)
        {
            record[s[l]]--;
            if (record[s[l]] == 0)
            {
                record.erase(s[l]);
            }
            l++;
            if (l > r)
            {
                r = l;
                record[s[l]]++;
            }
        }
        else
        {
            record[s[r + 1]]++;
            r++;
        }
    }
    return g;
}

int main()
{
    string s = "AAAB";
    int k = 0;
    int result = longest_repeating_character_replacement(s, k);
    cout << "longest_repeating_character_replacement :- " << result << endl;

    return 0;
}