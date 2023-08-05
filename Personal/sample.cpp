#include<stdio.h>
int main()
{
    int a,b,c,d;
    printf("Enter 1st Number\n");
    scanf("%d",&a);
    printf("Enter 2nd Number\n");
    scanf("%d",&b);
    printf("c=1 for addition,\nc=2 for subtraction,\nc=3 for multiplication,\nc=4 for division\n");
    
    while (1){
    printf("Enter c value\n");
    scanf("%d",&c);
    if(c>0 && c<5){
    switch(c){
        case 1 :
        d=a+b;
        printf("Sum=%d",d);
        break;
        case 2 :
        d=a-b;
        printf("Diff=%d",d);
        break;
        case 3 :
        d=a*b;
        printf("Prod=%d",d);
        break;
        case 4 :
        d=a*b;
        printf("Div=%d",d);
        break;
    }
    break;
    }
    else {
        printf("invalid\n");
    }
    }
    return 0;
}