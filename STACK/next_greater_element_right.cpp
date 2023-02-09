#include <bits/stdc++.h>
using namespace std;

void nge(vector<int> &nums) {
    stack<int> st;
    vector<int> ans(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        // 1,5,2,3,6,9
        // 5 6 3 6 9 0
        while(!st.empty() && nums[i] > nums[st.top()]) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top() - i;
        }
        st.push(i);
    }

    for (auto &&i : ans)
    {
        cout << i << ' ';
    }
}

int main()
{
    vector<int> nums = {89,62,70,58,47,47,46,76,100,70};
    // 1,5,2,3,6,9
    // 5 6 3 6 9 0
    nge(nums);
    
    return 0;
}