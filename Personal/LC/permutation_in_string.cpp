#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool permutation_in_string(string s1, string s2)
{
    unordered_map<char, int> check;
    unordered_map<char, int> record;
    int l, r;
    l=0;
    r=0;
    for (int i = 0; i < s1.length(); i++)
    {   
        check[s1[i]]++;
    }
    if (s1.length() > s2.length())
    {
        return false;
    }
    else{
        while(r<s2.length()){
            record[s2[r]]++;
            if(record[s2[r]]>check[s2[r]]){
                while(l<=r){
                    record[s2[l]]--;
                    l++;
                    if(record[s2[r]]==check[s2[r]]){
                        break;
                    }
                }
            }
            if((r-l+1)==s1.length()){
                return true;
            }
            r++;
        }
        return false;
    }
}

int main()
{
    string s1 = "hello";
    string s2 = "ooolleoooleh";
    bool result = permutation_in_string(s1, s2);
    cout << "permutation_in_string :- " << result << endl;
    return 0;
}