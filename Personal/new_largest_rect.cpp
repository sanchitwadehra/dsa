#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {4, 2, 4, 1, 3, 2, 4};
    vector<pair<int, int>> sortedVecWithIndices;

    for (int i = 0; i < vec.size(); i++) {
        sortedVecWithIndices.push_back(make_pair(vec[i], i));
    }

    sort(sortedVecWithIndices.begin(), sortedVecWithIndices.end());

    vector<int> sortedIndices;

    for (int i = 0; i < sortedVecWithIndices.size(); i++) {
        sortedIndices.push_back(sortedVecWithIndices[i].second);
    }

    for (int i = 0; i < sortedIndices.size(); i++) {
        cout << "Element: " << vec[sortedIndices[i]] << " at index: " << sortedIndices[i] << endl;
    }

    int c=0;
    int greatestNumber;

    return 0;
}
