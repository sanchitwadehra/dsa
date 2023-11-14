#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

string minimum_window_substring(string t, string s)
{
    unordered_map<char, int> check;
    unordered_map<char, int> record;
    int l, r, n;
    pair<int, int> smallest;
    smallest.first = 0;
    smallest.second = s.length();
    l = 0;
    r = 0;
    n = 0;
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
            if (check.find(s[r]) != check.end() && record.find(s[r]) != record.end())
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
                            record[s[l]]--;
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
                        break;
                    }
                    n--;
                }
            }
        }
    }
    string result(smallest.second, ' '); // Initialize with the size of smallest.second
    for (int i = 0; i < smallest.second; i++)
    {
        result[i] = s[smallest.first + i];
    }
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