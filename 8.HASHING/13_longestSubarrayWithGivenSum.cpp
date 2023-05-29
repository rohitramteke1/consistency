#include <bits/stdc++.h>
using namespace std;

// O(N ^ 2)
int brute(int arr[], int n, int target) {
    int res = 0;

    for (int i=0; i<n; i++) {
        int curr_sum = 0;

        for (int j=i; j<n; j++) {
            curr_sum += arr[j];

            if (curr_sum == target)
                res = max(res, j - i + 1);
        }

    }
    return res;
}

// Alter effiecient solution
// O(N) + O(N)
int subArrayWithGivenSum(int arr[], int n, int k) {
    unordered_map<int, int> mp;
    int pref_sum = 0;
    int maxLen = 0;

    for (int i=0; i<n; i++) {
        pref_sum += arr[i];

        if ( pref_sum == k ) 
            maxLen = max(maxLen, i + 1);

        if ( mp.find( pref_sum ) == mp.end() ) {
            mp[ pref_sum ] = i;
        }

        if (mp.find(pref_sum - k) != mp.end()) {
            maxLen = max(maxLen, i - mp[ pref_sum - k ]);
        }
    }

    return maxLen;
}

int main()
{
    int arr[] = {10, 2, -2, -20, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << brute(arr, n, 0) << endl;
    // cout << subArrayWithGivenSum(arr, n, 0) << endl;

    
    return 0;
}