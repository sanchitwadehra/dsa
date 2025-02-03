#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int g,l,r,p;
    l=0;
    r=height.size()-1;
    g=0;
    while(l<r){
        p=min(height[l],height[r])*(r-l);
        if(p>g){
            g=p;
        }
        if(height[l]==min(height[l],height[r])){
            l++;
        }
        else{
            r--;
        }
    }
    cout<<g;
    return 0;
}
