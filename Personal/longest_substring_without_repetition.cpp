#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>
using namespace std;

int main()
{
    string s=" ";
    unordered_set<char> bag;
    int g;
    g=0;
    for(int i=0;i<s.size();i++)
    {
        if(bag.find(int(s[i]))==bag.end() && i!=(s.size()-1)){
            bag.insert(int(s[i]));
        }else if(i==s.size()-1){
            bag.insert(int(s[i]));
            if(bag.size()>g){
                g=bag.size();
            }
        }
        else{
            if(bag.size()>g){
                g=bag.size();
            }
            bag.clear();
            bag.insert(int(s[i]));
        }
    }
    cout<<g<<endl;
    return 0;
}
