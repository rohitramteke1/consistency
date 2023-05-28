#include <bits/stdc++.h>
using namespace std;

// O(N ^ 2)
bool brute(int arr[], int n, int target) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] + arr[j] == target)
                return 1;
        }
    }
    return 0;
}

// O(N) + O(N)
bool twoSum(int arr[], int n, int target) {
    unordered_map<int, int> mp; // you can unordered_set<int> also
    for (int i=0; i<n; i++) {
        int required = target - arr[i];
        if ( mp.find(required) != mp.end() )
            return 1;
        mp[ arr[i] ] = 1;
    }

    return 0;
}

int main()
{
    int arr[] = {11, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << brute(arr, n, 10) << endl;
    cout << twoSum(arr, n, 10) << endl;
    
    return 0;
}