#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool compatibility(float a, float b, float apos, float posdiff, float targetpos) {
        if (b < a) {
            if ((((posdiff / (a - b)) * a) + apos) <= targetpos) {
                return true;
            }
        }
        return false;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> record;
        stack<float> manager; // Change the stack type to float
        float prevkey; // Change the type of prevkey to float
        int n = 0; // Initialize n to 0
        for (int i = 0; i < position.size(); i++) {
            record[position[i]] = speed[i];
        }
        for (const auto& pair : record) {
            if (manager.empty()) {
                manager.push(pair.second);
            } else {
                if (compatibility(manager.top(), static_cast<float>(pair.second), prevkey, prevkey - static_cast<float>(pair.first()), static_cast<float>(target))) {
                    manager.pop();
                    manager.push(static_cast<float>(pair.second));
                } else {
                    manager.pop();
                    manager.push(static_cast<float>(pair.second));
                    n++;
                }
            }
            prevkey = static_cast<float>(pair.first());
        }
        if (!manager.empty()) {
            manager.pop();
            n++;
        }
        return n;
    }
};

int main() {
    Solution solution;

    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int target = 12;

    int result = solution.carFleet(target, position, speed);

    cout << "Output: " << result << endl;

    return 0;
}
