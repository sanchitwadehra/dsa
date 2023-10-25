#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int main() {
    vector<int> histogram = {2,1,5,6,2,3};

    map<int, int> valueToIndexMap; // Hashmap to store values and their indices
    for (int i = 0; i < histogram.size(); ++i) {
        int value = histogram[i];
        valueToIndexMap[value] = i; // Store the value and its index in the hashmap
    }
    // Now you can access values along with their original indices
    for (const auto& pair : valueToIndexMap) {
        cout << "Value: " << pair.first << ", Original Index: " << pair.second << endl;
    }

    

    return 0;
}