#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
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

    
}