// Linear and binary search
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    char yn;
    cout << "Enter the length of array :- " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements into the array :- " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nSo the array you entered is :- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int s;
label_1:
    cout << "Enter the element you want to search :- " << endl;
    cin >> s;
    int f;
    f = 0;
label_2:
    int lb;
    cout << "Do you want to use 1-Linear Search or 2-Binary Search :- " << endl;
    cin >> lb;
    if (lb != 1 && lb != 2)
    {
        cout << "\nPlease enter a valid selection either 1-Linear Search or 2-Binary Search" << endl;
        goto label_2;
    }
    if (lb == 1)
    {
        // Linear Search
        for (int i = 0; i < n; i++)
        {
            if (s == arr[i])
            {
                cout << "Element Found :-) \n"
                     << "Index :- " << arr[i] << "\nValue :- " << s;
                f++;
                cout << "\nDo you want to retry [Y/N]:- " << endl;
                cin >> yn;
                if (yn == 'Y' || yn == 'y')
                {
                    goto label_1;
                }
                else
                {
                    cout << "\nThanks for operating me :-)" << endl;
                }
            }
        }
    }
    if (lb == 2)
    {
        // Binary Search
        int carr[n];
        // Copying the Array
        for (int i = 0; i < n; i++)
        {
            carr[i] = arr[i];
        }
        sort(carr, carr + n);
        /*
        cout << "\nSo the array you entered is :- " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << carr[i] << " ";
        }
        cout << endl;*/
        int lp, rp;
        lp = 0;
        rp = n - 1;

        while (lp <= rp)
        {
            int mid = (lp + rp) / 2;
            if (carr[mid] == s)
            {
                cout << "Element Found" << endl;
                f++;
                cout << "\nDo you want to retry [Y/N]:- " << endl;
                cin >> yn;
                if (yn == 'Y' || yn == 'y')
                {
                    goto label_1;
                }
                else
                {
                    cout << "\nThanks for operating me :-)" << endl;
                }
            }
            else if (carr[mid] < s)
            {
                lp = mid + 1;
            }
            else
            {
                rp = mid - 1;
            }
        }
    }
    if (f == 0)
    {
        cout << "\nSorry element not found in the Array" << endl;
        cout << "\nDo you want to retry [Y/N]:- " << endl;
        cin >> yn;
        if (yn == 'Y' || yn == 'y')
        {
            goto label_1;
        }
        else
        {
            cout << "\nThanks for operating me :-)" << endl;
        }
    }
    return 0;
}