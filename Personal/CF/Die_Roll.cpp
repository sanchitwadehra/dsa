#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int y,w;
    cin>>y>>w;
    int m=max(y,w);
    int n,d=6;
    n=6-m+1;
    if(n==1){
        cout<<"1/6";
    }
    else if(n==2){
        cout<<"1/3";
    }
    else if(n==3){
        cout<<"1/2";
    }
    else if(n==4){
        cout<<"2/3";
    }
    else if(n==5){
        cout<<"5/6";
    }
    else{
        cout<<"1/1";
    }
}