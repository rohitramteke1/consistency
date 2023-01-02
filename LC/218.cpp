#include <bits/stdc++.h>
using namespace std;

int findKthLargest (vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int> > pq; // minimum-priority-queue
    
    for (int i = 0; i < k; i++)
        pq.push(nums[i]);
    
    for (int i = k; i < nums.size(); i++)
    {
        if(pq.top() < nums[i]) {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    
    return pq.top();
}

int main()
{
    vector<int> nums = {5,7,8,2,0,3};
    // 0 2 3 5 7 8
    //         ↑
    int k = 2;
    cout << findKthLargest(nums, k) << endl;
    
    return 0;
}