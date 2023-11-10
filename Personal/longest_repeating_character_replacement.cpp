#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

auto compare = [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    };

int longest_repeating_character_replacement(string s, int k)
{
    unordered_map<char,int> record;
    int l,r,g;
    g=0;
    l=0;
    r=0;
    char top_element;
    int temp_top_element_value;
    int temp_k;
    temp_k=0;
    while(r<s.length()){
        if(record.find(s[r])==record.end()){
            record[s[r]]=1;
            cout<<s[r]<<" "<<record[s[r]]<<endl;
            if((r-l+1)>g){
                g=(r-l+1);
            }
            temp_k++;
            r++;
        }
        else if(s[r]==top_element || (temp_k+1)<=k){
            if(s[r]==top_element){
                record[top_element]++;
                temp_top_element_value=record[top_element];
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
        auto it = max_element(record.begin(), record.end(), compare);
        top_element=it->first;
    }
    return g;
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
