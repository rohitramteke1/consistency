#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &arr, int x) {
    int count = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > x) {
            count++;
            ans = max(ans, count);
            continue;
        } else {
            count = 0;
        }
    }
    // check the last count with ans
    // if(count) {
    //     ans = max(ans, count);
    // }
    return count ? max(count, ans) : ans;
    // return ans;
}

int main()
{
    vector<int> arr = {4,1,5,3,6,9,7};
    cout <<longestSubarray(arr, 4);
    
    return 0;
}