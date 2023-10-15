#include <iostream>
using namespace std;

bool check(int a, int b)
{
    if (a * b > 0)
    {
        return true;
    }
    else if (a * b < 0)
    {
        return false;
    }
}

int main()
{
    int n, t;
    int neg=0;
    int pos=0;
    int temp_cont = 0;
    int diff;
    label:
    cout << "You have to enter only -ve and +ve integeres into the array :-" << endl;
    cout << "Enter the size of the array :- " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the -ve and +ve integers only :- " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {
            neg++;
        }
        if (arr[i] > 0)
        {
            pos++;
        }
        if(arr[i]==0){
            goto label;
        }
    }
    diff = pos - neg;
    for (int i = 0; i < n - 1; i++)
    {
        if (check(arr[i], arr[i + 1]))
        {
            int j = i + 1;
            //cout << "t" << endl;
            int count = 0;
            int conf = 0;
            while (check(arr[i], arr[j]))
            {
                j++;
                count++;
                if (!check(arr[i], arr[j]))
                {
                    conf++;
                }
            }
            if (count > 0 && conf > 0)
            {
                temp_cont++;
                if (temp_cont == diff || temp_cont == (diff * (-1)))
                {
                    
                    break;
                }
                t = arr[i + 1];
                arr[i + 1] = arr[j];
                arr[j] = t;
            }
            count = 0;
            conf = 0;
        }
    }
    cout << "The alternative array is shown below :- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}