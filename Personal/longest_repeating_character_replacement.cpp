#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longest_repeating_character_replacement(string s, int k)
{
    unordered_map<char, int> record;
    int l, r, g,gi;
    g = 0;
    l = 0;
    r = 0;
    gi=0;
    char top_element;
    int temp_top_element_value;
    int temp_k;
    temp_k = 0;

    auto compare = [](const auto &lhs, const auto &rhs)
    {
        return lhs.second < rhs.second;
    };

    while (r < s.length())
    {
        if (r == 0)
        {
            if (record.find(s[r]) == record.end())
            {
                record[s[r]] = 1;
                if ((r - l + 1) > g)
                {
                    g = (r - l + 1);
                    gi=l;
                }
                r++;
            }
        }
        else if (record.find(s[r]) == record.end() && (temp_k + 1) <= k)
        {
            record[s[r]] = 1;
            if ((r - l + 1) > g)
            {
                g = (r - l + 1);
                gi=l;
            }
            r++;
        }
        else if (s[r] == top_element || (temp_k + 1) <= k)
        {
            if (s[r] == top_element)
            {
                record[top_element]++;
            }
            else
            {
                record[s[r]]++;
            }
            if ((r - l + 1) > g)
            {
                g = (r - l + 1);
                gi=l;
            }
            r++;
        }
        else
        {
            record[s[l]]--;
            if (s[l] == 0)
            {
                record.erase(s[l]);
            }
            l++;
            record[s[r]] = 1;
            r++;
        }
        auto it = max_element(record.begin(), record.end(), compare);
        top_element = it->first;
        temp_k = r - record[top_element];
    }
    cout<<"gi "<<gi<<endl;
    return g;
}

int main()
{
    string s = "ACBAAAABBA";
    int k = 1;
    int result = longest_repeating_character_replacement(s, k);
    cout << "longest_repeating_character_replacement :- " << result << endl;

    return 0;
}

/*
int g;
    g=0;
    for(int i=0;i<record.size();i++){
        if(record[i].second>g){
            g=i;
        }
    }
    pair<char,int> temp;
    temp.first=record[g].first;
    temp.second=record[g].second;
    record.erase(record.begin()+g);
    record.insert(record.begin(),temp);
*/
