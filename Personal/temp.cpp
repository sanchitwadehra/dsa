#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int max[2];
        vector<int> result;
        if (k == 0)
        {
            return result;
        }
        else if (k == 1)
        {
            return nums;
        }
        else if (k > nums.size())
        {
            return result;
        }
        else if (k == nums.size())
        {
            max[1] = nums[0];
            /*if(nums[1]>max[1]){
                max[0]=max[1];
                max[1]=nums[1];
            }
            else{
                max[0]=nums[1];
            }*/
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] > max[1])
                {
                    max[1] = nums[i];
                }
            }
            result.push_back(max[1]);
            return result;
        }
        else if (k < 0)
        {
            return result;
        }
        else
        {
            for (int i = 0; i <= nums.size()-k; i++)
            {
                if (i == 0)
                {
                    max[1] = nums[0];
                    max[0] = 0;
                    for (int j = 1; j < k; j++)
                    {
                        if (nums[j] >= max[1])
                        {
                            max[1] = nums[j];
                            max[0] = j;
                        }
                    }
                    result.push_back(max[1]);
                }
                else
                {
                    if (i <= max[0])
                    {
                        if (nums[i + k - 1] >= max[1])
                        {
                            max[1] = nums[i + k - 1];
                            max[0] = i + k - 1;
                        }
                        result.push_back(max[1]);
                    }
                    else
                    {
                        max[1] = nums[i];
                        max[0] = i;
                        for (int j = i + 1; j < i + k; j++)
                        {
                            if (nums[j] >= max[1])
                            {
                                max[1] = nums[j];
                                max[0] = j;
                            }
                        }
                        result.push_back(max[1]);
                    }
                }
            }
            return result;
        }
    }
};