#include <bits/stdc++.h>
using namespace std;

int kth_greater(vector<int> &nums, int k) {
    // make minHeap
    priority_queue<int, vector<int>, greater<int> > pq;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        pq.push(nums[i]);
        if(pq.size() > k)
            pq.pop();
    }
    return pq.top();
}
int kth_smaller(vector<int> &nums, int k) {
    // make maxHeap
    priority_queue<int> pq; 

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        pq.push(nums[i]);
        if(pq.size() > k)
            pq.pop();
    }
    
    return pq.top();
}

int main()
{
    vector<int> nums = {5,4,7,2,0,1,6,8};
    int k = 4;
    int k_greater = kth_greater(nums, k);
    int k_smaller = kth_smaller(nums, k);
    
    cout << k_greater << ' ' << k_smaller << endl;

    return 0;
}