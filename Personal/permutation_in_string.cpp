#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool permutation_in_string(string s1, string s2)
{
    unordered_map<char, int> rs1;
    unordered_map<char, int> rs2;
    int l, r, n;
    n = s1.length();
    l = 0;
    r = l + (n - 1);
    for (int i = 0; i < s1.length(); i++)
    {
        rs1[s1[i]]++;
    }
    if (s1.length() > s2.length())
    {
        return false;
    }
    else
    {
        while (r < s2.length() && l < s2.length())
        {
            for (int i = l; i <= r; i++)
            {
                rs2[s2[i]]++;
                if (rs2[s2[i]] == rs1[s2[i]] || rs2[s2[i]] < rs1[s2[i]])
                {
                    if (i == r)
                    {
                        return true;
                    }
                }
                else
                {
                    if (rs2[s2[i]] > 1)
                    {
                        for (int j = i; j >= l; j--)
                        {
                            if (s2[j] == s2[i])
                            {
                                if (rs2[s2[j]] == rs1[s2[j]])
                                {
                                    l = j;
                                    r = (l + 1) + (n - 1);
                                    rs2.clear();
                                    break;
                                }
                            }
                            rs2[s2[j]]--;
                        }
                    }
                    else
                    {
                        l = i + 1;
                        r = l + (n - 1);
                        rs2.clear();
                        break;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    string s1 = "hello";
    string s2 = "ooolleoooleh";
    bool result = permutation_in_string(s1, s2);
    cout << "permutation_in_string :- " << result << endl;
    return 0;
}