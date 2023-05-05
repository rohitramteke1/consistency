#include <bits/stdc++.h>
using namespace std;

int TwoSum(int *arr, int n, int sum) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if ( mp.find(sum - arr[i]) != mp.end() ) {
            return 1;
        }
        mp[arr[i]] = i;
    }
    
    return 0;
}

int main()
{
    int arr[] = {3,5,9,2,8,10,11};
    int x = 17;
    cout << TwoSum(arr, 7, x);
    return 0;
}