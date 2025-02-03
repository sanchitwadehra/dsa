#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int l, r, s;
    auto it = std::max_element(height.begin(), height.end());
    std::cout << it - height.begin() << std::endl;
    l = 0;
    r = 0;
    s = 0;
    for (r = 0; r < it - height.begin(); r++)
    {
        if (height[r] >= height[l])
        {
            l = r;
        }
        else
        {
            s += (height[l] - height[r]);
        }
    }
    l=height.size()-1;
    r=height.size()-1;
    for(r=height.size()-1; r>=it-height.begin();r--){
        if(height[r]>=height[l]){
            l=r;
        }
        else{
            s+=height[l]-height[r];
        }
    }
    cout << s;
    return 0;
}
