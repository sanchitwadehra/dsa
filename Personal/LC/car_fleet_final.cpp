#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution
{
public:
    bool compatibility(float a, float b, float apos, float posdiff, float targetpos)
    {
        if (b < a)
        {
            if ((((posdiff / (a - b)) * a) + apos) <= targetpos)
            {
                return true;
            }
        }
        return false;
    }

    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        //cout<<"testing came inside"<<endl;
        map<int, int> record;
        stack<float> brvalues;
        stack<float> brindexes;
        stack<float> manager; // Change the stack type to float
        float prevkey;        // Change the type of prevkey to float
        int n = 0;            // Initialize n to 0
        for (int i = 0; i < position.size(); i++)
        {
            record[position[i]] = speed[i];
            //cout<<"MApping done"<<endl;
        }
        for (const auto &pair : record)
        {
            if (manager.empty())
            {
                manager.push(pair.second);
                //cout<<"first element pushed"<<endl;
                //cout<<"index "<<pair.first<<" values "<<pair.second<<endl;
            }
            else
            {
                //cout<<"index "<<pair.first<<" values "<<pair.second<<endl;
                if (compatibility(static_cast<float>(manager.top()), static_cast<float>(pair.second), prevkey, static_cast<float>(pair.first) - prevkey, static_cast<float>(target)))
                {
                    //brvalues.push(manager.top());
                    //brindexes.push(prevkey);
                    //cout<<"index "<<pair.first<<" values "<<pair.second<<endl;
                    manager.pop();
                    manager.push(static_cast<float>(pair.second));
                    //n++;
                    label:
                    if(!brvalues.empty()){
                        if (compatibility(static_cast<float>(brvalues.top()), static_cast<float>(pair.second), brindexes.top(), static_cast<float>(pair.first) - brindexes.top(), static_cast<float>(target))){
                        brindexes.pop();
                        brvalues.pop();
                        n--;
                        goto label;
                    }
                    }
                }
                else
                {
                    brvalues.push(manager.top());
                    brindexes.push(prevkey);
                    manager.pop();
                    manager.push(static_cast<float>(pair.second));
                    n++;
                }
            }
            prevkey = static_cast<float>(pair.first);
        }
        if (!manager.empty())
        {
            manager.pop();
            n++;
        }
        return n;
    }
};

int main()
{
    Solution solution;

    vector<int> position = {0, 2, 4};
    vector<int> speed = {4, 2, 1};
    int target = 100;

    //cout<<"Testing before"<<endl;

    int result = solution.carFleet(target, position, speed);

    //cout<<"Testing after"<<endl;

    cout << "Output: " << result << endl;

    return 0;
}
