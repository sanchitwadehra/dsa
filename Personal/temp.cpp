#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool minimum_window_substring(string t, string s)
{
    unordered_map<char, int> check;
    unordered_map<char, int> record;
    int l, r;
    l=0;
    r=0;
    for (int i = 0; i < t.length(); i++)
    {   
        check[t[i]]++;
    }
    if (t.length() > s.length())
    {
        return false;
    }
    else{
        while(r<s.length()){
            record[s[r]]++;
            if(record[s[r]]>check[s[r]]){
                while(l<=r){
                    record[s[l]]--;
                    l++;
                    if(record[s[r]]==check[s[r]]){
                        break;
                    }
                }
            }
            if((r-l+1)==t.length()){
                return true;
            }
            r++;
        }
        return false;
    }
}

int main()
{
    string t = "hello";
    string s = "ooolleoooleh";
    bool result = minimum_window_substring(t, s);
    cout << "minimum_window_substring :- " << result << endl;
    return 0;
}