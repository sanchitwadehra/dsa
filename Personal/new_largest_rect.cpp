#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> heights = {1,2,1};
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

    int checkValue, greatestNumber, lk, rk,lkDifference,rkDifference;
    int n = heights.size();

    for (int i = 0; i < sortedIndices.size(); i++)
    {
        cout << "Element: " << heights[sortedIndices[i]] << " at index: " << sortedIndices[i] << endl;
        if (i == 0)
        {
            greatestNumber = heights[sortedIndices[i]] * (sortedIndices.size());
        }
        else
        {
            lk=0;
            rk=n-1;
            /*
            if (sortedIndices[i] == 0)
            {
                lk = 0;
            }
            if (sortedIndices[i] == n - 1)
            {
                rk = n - 1;
            }
            */
            lkDifference = sortedIndices[i];
            rkDifference = n - sortedIndices[i] - 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (sortedIndices[j] < sortedIndices[i])
                {
                    if ((sortedIndices[i] - sortedIndices[j]) < lkDifference)
                    {
                        lk = sortedIndices[j];
                        lkDifference=sortedIndices[i]-lk;
                    }
                }
                if (sortedIndices[j] > sortedIndices[i])
                {
                    if ((sortedIndices[j] - sortedIndices[i]) < rkDifference)
                    {
                        rk = sortedIndices[j];
                        rkDifference=rk-sortedIndices[i];
                    }
                }
            }
            if (lk == 0)
            {
                checkValue = (rk - lk) * heights[sortedIndices[i]];
            }
            else if (rk == n - 1)
            {
                checkValue = (rk - lk) * heights[sortedIndices[i]];
            }
            else
            {
                checkValue = (rk - lk - 1) * heights[sortedIndices[i]];
            }
            if (checkValue > greatestNumber)
            {
                greatestNumber = checkValue;
            }
        }
    }

    cout << greatestNumber << endl;
    return 0;
}
