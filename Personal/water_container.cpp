#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int g,l,r,p;
    g=0;
    while(l<r){
        p=min(height[l],height[r])*(r-l);

    }
    return 0;
}
