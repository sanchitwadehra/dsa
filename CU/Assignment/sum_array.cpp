#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    cout << "Sum of elements: " << sum << endl;

    return 0;
}