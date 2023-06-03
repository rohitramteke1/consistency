// Link: https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
public:
    long long int findSubarray(vector<long long int> &arr, int n ) {
        unordered_map<long long, int> mp;
        mp[0] = 1;
        long long count = 0;
        long long prefix_sum = 0;
        
        for (int i = 0; i < n; i++) {
            prefix_sum += arr[i];
            count += mp[prefix_sum];
            mp[prefix_sum]++;
        }
        
        return count;
    }
};