#include <bits/stdc++.h>
using namespace std;

// O(N ^ 2)
bool brute(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int curr_sum = 0;
        for (int j=i; j<n; j++) {
            curr_sum += arr[j];
            if (curr_sum == 0)
                return 1;
        }
    }
    return 0;
}

// effiecient solution
// O(N) + O(N)
bool subArrayWith0Sum(int arr[], int n) {
    unordered_map<int, int> mp;
    int pref_sum = 0;

    for (int i=0; i<n; i++) {
        pref_sum += arr[i];

        if (pref_sum == 0)
            return 1;

        if ( mp.find(pref_sum) != mp.end() )
            return 1;
        mp[pref_sum] = 1;
    }

    return 0;
}

int main()
{
    int arr[] = {4,-3,2,1};
    // int arr[] = {10, -10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << brute(arr, n) << endl;
    cout << subArrayWith0Sum(arr, n) << endl;

    
    return 0;
}