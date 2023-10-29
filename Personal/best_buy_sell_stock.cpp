#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    int l,r,g;
    l=0;
    g=0;
    for(r=1;r<prices.size();r++){
        if(prices[r]<=prices[l]){
            l=r;
        }
        if((prices[r]-prices[l])>g){
            g=(prices[r]-prices[l]);
        }
    }
    cout<<g;
    return 0;
}
