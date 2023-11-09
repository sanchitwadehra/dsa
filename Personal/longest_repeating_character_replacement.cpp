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
        top_element=it->first;
        if(record.find(s[r])==record.end()){
            record[s[r]]=1;
            if((r-l+1)>g){
                g=(r-l+1);
            }
            r++;
        }
        else if(s[r]==record[top_element] || (temp_k+1)<=k){
            if(s[r]==record[top_element]){
                record[top_element]++;
            }
            else{
                record[s[r]]++;
                temp_k++;
            }
            if((r-l+1)>g){
                g=(r-l+1);
            }
            r++;
        }
        else{
            record[s[l]]--;
            if((r-l+1)>g){
                g=(r-l+1);
            }
            l++;
            r++;
        }
    }
    cout<<g;
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
