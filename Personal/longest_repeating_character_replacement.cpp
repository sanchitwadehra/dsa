#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void most_popular_set_top(vector<pair<char, int> > &record){
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
}

int longest_repeating_character_replacement(std::string s, int k)
{
    int s = s.size();
    vector<pair<char, int> > record;
    int l,r;
    l=0;
    r=0;
    while(r<s.size()){

    }
}

int main()
{
    std::string s = "AABABBA";
    int k = 2;
    int result = longest_repeating_character_replacement(s, k);
    std::cout << "longest_repeating_character_replacement :- " << result << std::endl;

    return 0;
}
