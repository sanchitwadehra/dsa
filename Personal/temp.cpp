#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool validating(unordered_map<char, int> &record, unordered_map<char, int> &check)
{
    if (record.size() != check.size())
    {
        return false;
    }
    else
    {
        for (auto it = check.begin(); it != check.end(); it++)
        {
            if (record.find(it->first) == record.end())
            {
                return false;
            }
        }
        for (auto it = record.begin(); it != record.end(); it++)
        {
            if (check.find(it->first) != check.end())
            {
                if (it->second < check[it->first])
                {
                    return false;
                }
            }
        }
        return true;
    }
}

string minimum_window_substring(string t, string s)
{
    unordered_map<char, int> check;
    unordered_map<char, int> record;
    int l, r, k;
    pair<int, int> smallest;
    smallest.first = 0;
    smallest.second = s.length();
    l = 0;
    r = 0;
    k = 0;
    for (int i = 0; i < t.length(); i++)
    {
        check[t[i]]++;
    }
    if (t.length() > s.length())
    {
        return "";
    }
    else if (t.length() == s.length())
    {
        if (t.length() == 1)
        {
            if (t != s)
            {
                return "";
            }
            else
            {
                return s;
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            record[s[i]]++;
        }
        if (validating(record, check))
        {
            return s;
        }
        else
        {
            return "";
        }
    }
    else
    {
        while (r < s.length())
        {
            if (check.find(s[r]) != check.end())
            {
                record[s[r]]++;
            }
            while (l < r)
            {
                if (check.find(s[l]) != check.end())
                {
                    if ((record[s[l]] - 1) >= check[s[l]])
                    {
                        record[s[l]]--;
                    }
                    else
                    {
                        break;
                    }
                }
                l++;
            }
            if (validating(record, check))
            {
                if ((r - l + 1) < smallest.second)
                {
                    smallest.first = l;
                    smallest.second = (r - l + 1);
                }
                k++;
            }
            r++;
        }
    }
    if (k != 0)
    {
        string result = s.substr(smallest.first, smallest.second);
        return result;
    }
    else
    {
        return "";
    }
}

int main()
{
    string t = "b";
    string s = "a";
    string result = minimum_window_substring(t, s);
    cout << "minimum_window_substring :- " << result << endl;
    return 0;
}