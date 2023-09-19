#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
int findNthSmallest(const std::vector<int> &vec, int n)
{
    if (n <= 0 || n > vec.size())
    {
        // Handle out of range cases
        return -1; // You can choose an appropriate error code or behavior
    }

    std::vector<int> copy = vec;         // Make a copy to avoid modifying the original vector
    std::sort(copy.begin(), copy.end()); // Sort the copy in ascending order

    // The nth smallest value will be at index n - 1 in the sorted vector
    int nthSmallest = copy[n - 1];

    // Now, find the index of the nth smallest value in the original vector
    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] == nthSmallest)
        {
            return i; // Return the index of the nth smallest value
        }
    }

    // Handle the case where the value is not found (this shouldn't happen if the input is valid)
    return -1; // You can choose an appropriate error code or behavior
}
*/

struct CustomComparator {
    std::vector<int>& arr;

    CustomComparator(std::vector<int>& inputArray) : arr(inputArray) {}

    // Compare function to ensure elements are ordered correctly
    bool operator()(int a, int b) const {
        if (arr[a] == arr[b]) {
            // If elements are equal, compare their indices
            return a > b;
        }
        return arr[a] > arr[b];
    }
};

// Function to find the n-th smallest element's index
int findNthSmallestIndex(const std::vector<int>& nums, int n) {
    std::priority_queue<int, std::vector<int>, CustomComparator> minHeap(CustomComparator(const_cast<std::vector<int>&>(nums)));
    std::unordered_map<int, int> countMap; // To keep track of element counts

    for (int i = 0; i < nums.size(); ++i) {
        minHeap.push(i); // Push indices onto the min-heap
        countMap[nums[i]]++; // Update element count
    }

    int resultIndex = -1;
    while (n > 0) {
        if (!minHeap.empty()) {
            int currentIndex = minHeap.top();
            minHeap.pop();
            // Check if this element still has remaining occurrences
            if (countMap[nums[currentIndex]] > 0) {
                resultIndex = currentIndex;
                countMap[nums[currentIndex]]--; // Decrement element count
                n--;
            }
        } else {
            // If the heap is empty before finding the nth smallest element, break
            break;
        }
    }

    return resultIndex;
}

int main()
{

    string s = "([)]";
    /*
    cout<<"s[1] - "<<s[1]<<endl;
    cout<<"s[2] - "<<s[2]<<endl;
    if(s[1]==s[2]){
        cout<<"same"<<endl;
    }
    */
    int t = 0;
    unordered_map<char, int> counter;

    counter['('] = 0;
    counter['{'] = 0;
    counter['['] = 0;

    vector<int> set_diff_ind;
    char d;

    cout<<"set_diff_ind"<<endl;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        // cout<<c;
        if (c == '(' || c == '{' || c == '[')
        {
            counter[c]++;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (c == ')')
            {
                d = '(';
            }
            else if (c == '}')
            {
                d = '{';
            }
            else
            {
                d = '[';
            }
            counter[d]--;
            if (counter[d] == (-1))
            {
                t--;
            }
            if (counter['('] == 0 && counter['{'] == 0 && counter['['] == 0 && i != 0)
            {
                set_diff_ind.push_back(i);
                cout<<i<<endl;
            }
        }
        else
        {
            t = -1;
        }
    }

    //cout<<endl;

    //cout<<"deff_ind"<<endl;
    vector<int> diff_ind;
    diff_ind.push_back(set_diff_ind[0] + 1);
   // cout<<diff_ind[0]<<endl;
    for (int i = 0; i < set_diff_ind.size() - 1; i++)
    {
        diff_ind.push_back(set_diff_ind[i + 1] - set_diff_ind[i]);
       // cout<<diff_ind[i+1]<<endl;
    }

    //cout<<endl;

    for (int i = 0; i <= diff_ind.size() - 1; i++)
    {
        //cout<<"i - "<<i<<endl;
        int j = findNthSmallestIndex(diff_ind, i + 1);
        //cout<<"j - "<<j<<endl;
        int rp = set_diff_ind[j];
        int lp = set_diff_ind[j] - (diff_ind[j] - 1);
       // cout<<"(diff_ind[j]) / 2 - "<<(diff_ind[j])/2<<endl;
        for (int k = 0; k < (diff_ind[j]) / 2; k++)
        {
           // cout<<lp+k<<" "<<rp-k<<endl<<endl;
            if (s[rp-k] == ')')
            {
                s[rp-k] = '(';
            }
            else if (s[rp-k] == '}')
            {
                s[rp-k] = '{';
            }
            else
            {
                s[rp-k] = '[';
            }
            if (s[lp + k] != s[rp - k])
            {
                t--;
            }
        }
    }

    if(t<0){
        cout<<"invalid";
    }
    else if(t==0){
        cout<<"valid";
    }

    return 0;
}

/*
class Solution {
public:

    int findNthSmallest(const std::vector<int>& vec, int n) {
    if (n <= 0 || n > vec.size()) {
        // Handle out of range cases
        return -1; // You can choose an appropriate error code or behavior
    }

    std::vector<int> copy = vec; // Make a copy to avoid modifying the original vector
    std::sort(copy.begin(), copy.end()); // Sort the copy in ascending order

    // The nth smallest value will be at index n - 1 in the sorted vector
    int nthSmallest = copy[n - 1];

    // Now, find the index of the nth smallest value in the original vector
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == nthSmallest) {
            return i; // Return the index of the nth smallest value
        }
    }

    // Handle the case where the value is not found (this shouldn't happen if the input is valid)
    return -1; // You can choose an appropriate error code or behavior
}

    bool isValid(string s) {

      int t = 0;
    unordered_map<char, int> counter;

    counter['('] = 0;
    counter['{'] = 0;
    counter['['] = 0;

    vector<int> set_diff_ind;
    char d;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        // cout<<c;
        if (c == '(' || c == '{' || c == '[')
        {
            counter[c]++;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (c == ')')
            {
                d = '(';
            }
            else if (c == '}')
            {
                d = '{';
            }
            else
            {
                d = '[';
            }
            counter[d]--;
            if (counter[d] == (-1))
            {
                return false;
            }
            if (counter['('] == 0 && counter['{'] == 0 && counter['['] == 0 && i != 0)
            {
                set_diff_ind.push_back(i);
            }
        }
        else
        {
            t = -1;
        }
    }

    vector<int> diff_ind;
    diff_ind.push_back(set_diff_ind[0] + 1);
    for (int i = 0; i < set_diff_ind.size() - 1; i++)
    {
        diff_ind.push_back(set_diff_ind[i + 1] - set_diff_ind[i]);
    }

    for (int i = 0; i <= diff_ind.size() - 1; i++)
    {
        int j = findNthSmallest(diff_ind, i + 1);
        int rp = diff_ind[j];
        int lp = set_diff_ind[j] - (diff_ind[j] - 1);
        for (int k = 0; k < (diff_ind[j]) / 2; k++)
        {
            if (s[lp + k] == s[rp - k])
            {
                return false;
            }
        }
    }

    return true;

    }
};
*/