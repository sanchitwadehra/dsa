#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int findNthSmallest(const std::vector<int>& vec, int n) {
    if (n <= 0 || n > vec.size()) {
        // Handle out of range cases
        return -1; // You can choose an appropriate error code or behavior
    }

    std::vector<int> copy = vec; // Make a copy to avoid modifying the original vector
    std::sort(copy.begin(), copy.end()); // Sort the copy in ascending order

    // The nth smallest value will be at index n - 1 in the sorted vector
    int nthSmallest = copy[n - 1];

    // Now, find the index of the nth smallest value in the original vector
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == nthSmallest) {
            return i; // Return the index of the nth smallest value
        }
    }

    // Handle the case where the value is not found (this shouldn't happen if the input is valid)
    return -1; // You can choose an appropriate error code or behavior
}

bool main()
{

    string s = "({[]}){()}}";
    unordered_map<char, int> counter;

    counter['('] = 0;
    counter['{'] = 0;
    counter['['] = 0;

    vector<int> set_diff_ind;
    char d;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
        {
            counter[c]++;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (c == ')')
            {
                d = '(';
            }
            else if (c == '}')
            {
                d = '{';
            }
            else
            {
                d = '[';
            }
            counter[d]--;
            if (counter[d] == (-1))
            {
                return false;
            }
            if (counter['('] == 0 && counter['{'] == 0 && counter['['] == 0 && i != 0)
            {
                set_diff_ind.push_back(i);
            }
        }
        else
        {
            return false;
        }
    }

    vector<int> diff_ind;
    diff_ind.push_back(set_diff_ind[0]+1);
    for (int i = 0; i < set_diff_ind.size() - 1; i++)
    {
        diff_ind.push_back(set_diff_ind[i + 1] - set_diff_ind[i]);
    }

    for(int i=0;i<diff_ind.size()-1;i++){
        
    }
}