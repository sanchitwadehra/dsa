#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

auto compare = [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    };

int main() {
    unordered_map<char, int> record = {{'A', 2}, {'B', 1}};
    char top_element;

    

    auto it = max_element(record.begin(), record.end(), compare);
    top_element = it->first;

    cout << "Key jiska max value hai: " << top_element << endl;

    return 0;
}
