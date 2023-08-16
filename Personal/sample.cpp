#include<iostream>
using namespace std;
int main(){
    float a,b,d;
    char c;
    aa:
    cout<<"Enter 1st Number :- "<<endl;
    cin>>a;
    cout<<"Enter 2nd Number :- "<<endl;
    cin>>b;
    ab:
    cout<<"enter a operation(+,-,*,/) :- "<<endl;
    cin>>c;
    switch(c){
        case '+':
        d=a+b;
        cout<<a<<" + "<<b<<" = "<<d<<endl;
        break;
        case '-':
        d=a-b;
        cout<<a<<" - "<<b<<" = "<<d<<endl;
        break;
        case '*':
        d=a*b;
        cout<<a<<" * "<<b<<" = "<<d<<endl;
        break;
        case '/':
        d=a/b;
        cout<<a<<" / "<<b<<" = "<<d<<endl;
        break;
        default:
        cout << "Not a valid operator. Do you want to try again ?[Y/N]:- "<<endl;
        cin>>c;
        if(c=='y' || c=='Y'){
            cout << "Do you want to enter new numbers ?[Y/N]"<<endl;
            cin>>c;
            if(c=='y' || c=='Y'){
                goto aa;
            }
            else{
                goto ab;
            }
        }
        else{
            cout<<"Thanks for operating me (-:"<<endl;
        }
        break;
    }
    return 0;
}