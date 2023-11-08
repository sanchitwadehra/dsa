#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longest_repeating_character_replacement(string s, int k)
{
    
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
