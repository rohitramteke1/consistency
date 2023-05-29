#include <bits/stdc++.h>
using namespace std;

// O(N ^ 2)
bool brute(int arr[], int n, int target) {
    for (int i=0; i<n; i++) {
        int curr_sum = 0;
        for (int j=i; j<n; j++) {
            curr_sum += arr[j];
            if (curr_sum == target)
                return 1;
        }
    }
    return 0;
}

// effiecient solution
// O(N) + O(N)
bool subArrayWithGivenSum(int arr[], int n, int target) {
    unordered_map<int, int> mp;
    int pref_sum = 0;

    for (int i=0; i<n; i++) {
        pref_sum += arr[i];

        if (pref_sum == target) {
            return 1;
        }

        if ( mp.find(pref_sum - target) != mp.end() ) {
            return 1;
        }
        mp[pref_sum] = i;
    }

    return 0;
}

int main()
{
    int arr[] = {10, 2, -2, -20, 10};
    // int arr[] = {10, -10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << brute(arr, n) << endl;
    cout << subArrayWithGivenSum(arr, n, -10) << endl;

    
    return 0;
}