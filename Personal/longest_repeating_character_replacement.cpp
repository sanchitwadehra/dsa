#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

int longest_repeating_character_replacement(string s, int k)
{
    unordered_map<char,int> record;
    int l,r,g;
    g=0;
    l=0;
    r=0;
    char top_element;
    int temp_k;
    while(r<=s.length()){
        auto it = max_element(record.begin(), record.end());
        if(record.find(s[r])==record.end()){
            record[s[r]]=1;
        }
        else if(s[r]==record[top_element] || (r-record[top_element])<=k){
            if(s[r]==record[top_element]){
                record[top_element]++;
            }
            else{
                temp_k++;
            }
            r++;
        }
        else{
            record[s[l]]--;
            l++;
            r++;
        }
    }
}

int main()
{
    string s = "AABABBA";
    int k = 2;
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
