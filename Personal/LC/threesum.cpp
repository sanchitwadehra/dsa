#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int l = i + 1;
            int r = nums.size() - 1;
            int target = -nums[i];

            while (l < r)
            {
                if (nums[l] + nums[r] == target)
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                }
                else if (nums[l] + nums[r] < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
    }
    return 0;
}
