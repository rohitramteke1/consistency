#include <bits/stdc++.h>
using namespace std;

// O(N ^ 2)
int brute(int arr[], int n, int target) {
    int ct = 0;

    for (int i=0; i<n; i++) {
        int curr_sum = 0;

        for (int j=i; j<n; j++) {
            curr_sum += arr[j];

            if (curr_sum == target)
                ct++;
        }

    }
    return ct;
}

// effiecient solution
// O(N) + O(N)
int subArrayWithGivenSum(int arr[], int n, int target) {
    unordered_map<int, int> mp;
    int pref_sum = 0;
    int ct = 0;

    for (int i=0; i<n; i++) {
        pref_sum += arr[i];

        if (pref_sum == target) {
            ct++;
        }

        if ( mp.find(pref_sum - target) != mp.end() ) {
            ct += mp[pref_sum - target];
        }

        mp[pref_sum]++;
    }

    return ct;
}

// Alter effiecient solution
// O(N) + O(N)
int subArrayWithGivenSum2(int arr[], int n, int target) {
    unordered_map<int, int> mp;
    int pref_sum = 0;
    int ct = 0;
    mp[0] = 1;

    for (int i=0; i<n; i++) {
        pref_sum += arr[i];

        if ( mp.find(pref_sum - target) != mp.end() ) {
            ct += mp[pref_sum - target];
        }

        mp[pref_sum]++;
    }

    return ct;
}

int main()
{
    int arr[] = {10, 2, -2, -20, 10};
    // int arr[] = {10, -10};
    int n = sizeof(arr)/sizeof(arr[0]);

    // cout << brute(arr, n, 0) << endl;
    cout << subArrayWithGivenSum(arr, n, 10) << endl;
    cout << subArrayWithGivenSum2(arr, n, 10) << endl;

    
    return 0;
}