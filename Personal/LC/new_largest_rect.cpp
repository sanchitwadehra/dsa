#include <iostream>
#include <vector>
#include<stack>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> heights = {1, 3, 0};
    int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        cout<<maxArea;
    return 0;
}
