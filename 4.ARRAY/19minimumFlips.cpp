#include <bits/stdc++.h>
using namespace std;

// mine code
int solve(vector<int> &arr, int value) {
    int n = arr.size();
    int subarr = 0;

    for (int i = 0; i < n; )
    {
        int j = i;
        bool flag = 0;
        while(j < n && arr[j] == value) {
            j++;
            flag = 1;
        }
        subarr += flag;
        j++;
        i = j;
    }
    return subarr;
}

// gfg code

int solve(vector<int> &arr) {
    int count = 0;
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        // we'll flip the seconds 
        // 1 1 0 0 0 1 1 1 0 0 1
        // 1   0     1     0   1
        // 1 0 1 0 1
        // minimum flips required 2

        if(arr[i] != arr[i-1]) {
            if(arr[i] != arr[0])
                cout << "from " << i << " to ";
            else
                cout << i-1 << endl;
        }
    }
    
    return count;
}


int main()
{
    vector<int> arr = {1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1};

    // our basic idea is count all the subarrys of 0s and 1s
    // pick up the min of both
    solve(arr);
    // cout << solve(arr, 0) << endl;
    // cout << solve(arr, 1) << endl;
    return 0;
}