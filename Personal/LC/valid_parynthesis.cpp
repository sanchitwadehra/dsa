#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{

    string s = "(){}}{";
    vector<int> stack;
    int t=0;
    char c=s[0];
    char d;
    if(c == ')' || c == '}' || c == ']'){
        t--;
    }
    stack.push_back(s[0]);
    for(int i=1;i<s.size();i++){
        c=s[i];
        if (c == '(' || c == '{' || c == '['){
            stack.push_back(c);
        }
        else if(c == ')' || c == '}' || c == ']'){
            if (c == ')')
            {
                d = '(';
            }
            else if (c == '}')
            {
                d = '{';
            }
            else
            {
                d = '[';
            }
            if(stack.back()==d){
                stack.pop_back();
            }else{
                cout<<"testing";
                t--;
            }
        }
    }
    if(t<0 || stack.size()!=0){
        cout<<"Invalid";
    }else{
        cout<<"valid";
    }
    return 0;
}
