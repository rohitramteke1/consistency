#include <bits/stdc++.h>
using namespace std;

// O(N^2) + O(1)
int brute(vector<int> &arr) {
    int n = arr.size();
    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int diff = arr[j] - arr[i];
            mx = max(diff, mx);
        }
    }

    return mx;
}

// O(N) + O(1)
int better(vector<int> &arr) {
    int n = arr.size();
    int minSoFar = arr[0];
    int res = arr[1] - arr[0];

    for (int i = 1; i < n; i++)
    {
        res = max(res, arr[i] - minSoFar);
        minSoFar = min(minSoFar, arr[i]);
    }
    
    return res;
}

int main()
{
    vector<int> arr = {2, 1, 3, 4, 2, 1, 5, 1, 7};
    cout << brute(arr) << endl;
    cout << better(arr) << endl;
    
    return 0;
}