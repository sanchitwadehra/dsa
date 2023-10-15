#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    std::vector<int> arr;
    int n;

    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        arr.push_back(x);
    }

    std::sort(arr.begin(), arr.end());

    std::vector<int> pos, neg;
    for (int x : arr)
    {
        if (x > 0)
            pos.push_back(x);
        else if (x < 0)
            neg.push_back(x);
    }

    arr.clear();
    while (!pos.empty() || !neg.empty())
    {
        if (!pos.empty())
        {
            arr.push_back(pos.back());
            pos.pop_back();
        }
        if (!neg.empty())
        {
            arr.push_back(neg.back());
            neg.pop_back();
        }
    }

    std::cout << "The alternating array is: ";
    for (int x : arr)
    {
        std::cout << x << ' ';
    }

    return 0;
}