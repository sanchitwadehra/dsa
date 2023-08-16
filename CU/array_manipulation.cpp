#include<iostream>
using namespace std;
int main()
{
    int n;
    label:
    cout<<"\nEnter the number of elements.";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements in the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int a;
    cout<<"Enter 1 to print the array,2 for the insertion of the element, 3 for the deletion of the element.";
    cin>>a;
    switch (a)
    {
        case 1:
    cout<<"\nElements in array are : ";
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<endl;
    }
    break;
    case 2:
    int pos,nv;
    cout<<"\nEnter the posisition on which you want to enter the new element.";
    cin>>pos;
    cout<<"Enter the value which you want to insert.";
    cin>>nv;
    if(pos>=0&&pos<n)
    {
        for(int l=n;l> pos; l--)
        {
            arr[l]=arr[l-1];
        }
        arr[pos] = nv;
        n++;
    }
    else
    {
        cout<<"Enter the correct posisition.";
    }
    cout<<"The elements in new array are : ";
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<endl;
    }
    break;
    case 3:
    int pos1;
    cout << "Enter the position of the element to delete: ";
    cin >> pos1;
    if (pos1 >= 0 && pos1 < n) {
        for (int f = pos1; f< (n-1); f++) {
            arr[f] = arr[f + 1];
        }
        n--;

    } 
    else
    {
    cout << "Invalid position for deletion." << endl;
    }
    cout<<"Elements in array after deletion of element :";
    for( int t=0;t<n;t++)
    {
        cout<<arr[t]<<endl;
    }
    break;
    default:
    cout<<"Enter the correct no. between 1-3.";
    }
    cout<<"Enter 0 to continue and 1 to terminate.";
    int b;
    cin>>b;
    if(b==0)
    {
        goto label;
    }
    else
    {
        exit(-0);
    }
    return 0;
}