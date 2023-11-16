#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool validating(unordered_map<char, int> &record, unordered_map<char, int> &check)
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

string minimum_window_substring(string t, string s)
{
    unordered_map<char, int> check;
    unordered_map<char, int> record;
    int l, r;
    pair<int, int> smallest;
    smallest.first = 0;
    smallest.second = s.length();
    l = 0;
    r = 0;
    for (int i = 0; i < t.length(); i++)
    {
        check[t[i]]++;
    }
    if (t.length() > s.length())
    {
        return "";
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
            }
            r++;
        }
    }
    string result = s.substr(smallest.first, smallest.second);
    return result;
}

int main()
{
    string t = "ABC";
    string s = "ADOBECODEBANC";
    string result = minimum_window_substring(t, s);
    cout << "minimum_window_substring :- " << result << endl;
    return 0;
}

/*

string result(smallest.second, ' '); // Initialize with the size of smallest.second
    for (int i = 0; i < smallest.second; i++)
    {
        result + s[smallest.first + i];
    }
    return result;

        while (r <= s.length())
        {
            if (check.find(s[r]) != check.end() && record.find(s[r]) == record.end())
            {
                record[s[r]]++;
                n++;
                if (n == t.length())
                {
                    if ((r - l + 1) < smallest.second)
                    {
                        smallest.first = l;
                        smallest.second = (r - l + 1);
                    }
                    while (l <= r)
                    {
                        if (record.find(s[l]) != record.end())
                        {
                            if (k > 0)
                            {
                                break;
                            }
                            record[s[l]]--;
                            if (record[s[l]] == 0)
                            {
                                record.erase(s[l]);
                            }
                            for (int i = l + 1; i <= r; i++)
                            {
                                if (s[i] != s[r])
                                {
                                    break;
                                }
                                else
                                {
                                    l++;
                                }
                            }
                            k++;
                        }
                        l++;
                    }
                    n--;
                }
            }
            k=0;
            r++;
        }
*/