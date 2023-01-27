#include <bits/stdc++.h>
using namespace std;

int equilibriumPoint(int arr[], int n) {
    vector<int> prefix(n+1, 0);
    vector<int> suffix(n+1, 0);
    
    for (int i = 0; i < n; ++i)
    {
        prefix[i+1] = prefix[i] + arr[i];
    }
    for (int i = 0; i < n; ++i)
    {
        suffix[n-1-i] = suffix[n-i] + arr[n-1-i];
    }
    for (int i = 0; i < n; i++)
    {
        if(prefix[i] == suffix[i+1]) return i+1;
    }
    return -1;
}

int e_point(int arr[], int n) {
    long long int left_sum = 0;
    long long int right_sum = 0;
    
    for (int i = 0; i < n; ++i)
        right_sum += arr[i];
    // cout << right_sum << endl;
    for (int i = 0; i < n; ++i)
    {
        left_sum += arr[i];
        if(left_sum > right_sum) return -1;
        if(left_sum == right_sum ) {
            return i + 1;
        }
        right_sum -= arr[i];
    }

    return -1;
}

int main()
{
    int arr[] = {27, 4, 25, 6, 6, 1, 27, 22, 19, 29, 6, 9, 36, 24, 6, 15, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout << equilibriumPoint(arr, n) << endl;
    cout << e_point(arr, n) << endl;
    
    return 0;
}