#include <bits/stdc++.h>
using namespace std;

// brute-force
void BFS_sliding_window(vector<int> &nums, int k) {
    int ans = 0;
    for (int j = 0; j < nums.size()-k+1; j++)
    {  
        int mx = nums[j];
        for (int i = j; i < j+k; i++)
            mx = max(mx, nums[i]);
        cout << mx << ' ';
    }
}

// better or Optimal
vector<int> better_sliding_window(vector<int> &arr, int k) {\
    list<int> l;
    vector<int> v;
    int i = 0, j = 0;
    while(j < arr.size()) {
        // candidate elements
        while(!l.empty() && l.back() < arr[j]) {
            l.pop_back();
        }
        l.push_back(arr[j]);
        // make a window
        if(j - i + 1 < k) j++;
        // 
        else if(j - i + 1 == k) {
            cout << l.front() << ' ';
            v.push_back(l.front());
            // now remove the calculation for the added element to the vector
            if(l.front() == arr[i]) {
                l.pop_front();
            }
            i++; j++;
        }
    }
    return v;
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    list<int>li;
    vector<int>ans;
    int i=0,j=0;
    
    while(j<nums.size()){
        
        while(li.size()>0 && li.back()<nums[j]){
            li.pop_back();
        }
        li.push_back(nums[j]);
        
        if(j-i+1 < k)j++;
        
        else if(j-i+1 == k){
            cout << li.front() << ' ';
            ans.push_back(li.front());
            
            if(nums[i] == li.front()){
                li.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
        
}
int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    BFS_sliding_window(nums, k);
    cout << endl;
    better_sliding_window(nums, k);
    cout << endl;
    maxSlidingWindow(nums, k);
    return 0;
}
