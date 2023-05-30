#include <bits/stdc++.h>
using namespace std;

// O(N ^ 2)
int brute(int arr[], int n) {
    sort(arr, arr + n);
    int cnt = 1;
    int res = 0;
    for (int i=1; i<n; i++) {

        if (arr[i-1] + 1 == arr[i]) 
            cnt++;
        else {
            res = max(res, cnt);
            cnt = 1;
        }

    }
    return max(cnt, res);
}

int countConsecutiveSubSequence(int arr[], int n) {
    unordered_map<int, int> mp;
    int consSubSeqLen = 0;

    for (int i=0; i<n; i++) 
        mp[ arr[i] ]++;
    
    for (int i=0; i<n; i++) {
        // 1,4,3,15,2,8,9,20
        if ( mp.find( arr[i] - 1 )  != mp.end() ) {
            continue;
        } else {
            int curr = 1;
            while ( mp.find( arr[i] + curr ) != mp.end() ) {
                curr += 1;
            }
            consSubSeqLen = max(consSubSeqLen, curr);
        }
    }

    return consSubSeqLen;
}

int main()
{
    int arr[] = {1,4,3,15,2,8,9,20};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << brute(arr, n) << endl;
    cout << countConsecutiveSubSequence(arr, n) << endl;

    
    return 0;
}