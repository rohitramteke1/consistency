#include <bits/stdc++.h>
using namespace std;

// O(N ^ 2)
int brute(int arr[], int n) {
    int res = 0;
    int c0 = 0;
    int c1 = 0;
    
    for (int i=0; i<n; i++) {

        for (int j=i; j<n; j++) {
            if (arr[j] == 0)
                c0++;
            else
                c1++;
            if (c1 == c0)
                res = max(res, j - i + 1);
        }

    }
    return res;
}

// Effiecient solution
// O(N) + O(N)
int lenghtOfEqualNoZeroesAndOnes(int arr[], int n, int k) {
    unordered_map<int, int> mp;
    k = 0;
    int pref_sum = 0;
    int maxLen = 0;

    for (int i=0; i<n; i++) 
        arr[i] == 0 ? arr[i] = -1 : 1;

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
    int arr[] = {0,1,1,1,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << brute(arr, n) << endl;
    cout << lenghtOfEqualNoZeroesAndOnes(arr, n, 0) << endl;

    
    return 0;
}