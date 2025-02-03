#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> heights = {1, 3, 0};
    vector<pair<int, int>> sortedheightsWithIndices;

    for (int i = 0; i < heights.size(); i++)
    {
        sortedheightsWithIndices.push_back(make_pair(heights[i], i));
    }

    sort(sortedheightsWithIndices.begin(), sortedheightsWithIndices.end());

    vector<int> sortedIndices;

    for (int i = 0; i < sortedheightsWithIndices.size(); i++)
    {
        sortedIndices.push_back(sortedheightsWithIndices[i].second);
    }

    int checkValue, greatestNumber, lk, rk, lkDifference, rkDifference, l, r;
    int n = heights.size();
    greatestNumber = 0;

    for (int i = 0; i < sortedIndices.size(); i++)
    {
        // cout << "Element: " << heights[sortedIndices[i]] << " at index: " << sortedIndices[i] << endl;
        if (heights[sortedIndices[i]] == 0)
        {
        }
        else
        {
            l = 0;
            r = 0;
            lk = -1;
            rk = n;
            lkDifference = sortedIndices[i]-lk;
            rkDifference = rk - sortedIndices[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (sortedIndices[j] < sortedIndices[i])
                {
                    if ((sortedIndices[i] - sortedIndices[j]) < lkDifference)
                    {
                        lk = sortedIndices[j];
                        lkDifference = sortedIndices[i] - lk;
                        l++;
                    }
                }
                if (sortedIndices[j] > sortedIndices[i])
                {
                    if ((sortedIndices[j] - sortedIndices[i]) < rkDifference)
                    {
                        rk = sortedIndices[j];
                        rkDifference = rk - sortedIndices[i];
                        r++;
                    }
                }
            }
            checkValue = (rk - lk - 1) * heights[sortedIndices[i]];
            if (checkValue > greatestNumber)
            {
                greatestNumber = checkValue;
            }
        }
    }

    cout << greatestNumber << endl;
    return 0;
}
