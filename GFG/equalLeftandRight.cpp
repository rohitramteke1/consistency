#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr) {
    int n = arr.size();

    int left = 0;
    int right = accumulate( begin(arr), end(arr), 0 );

    for (int i = 0; i < n; i++)
    {
        if(left + arr[i] == right)
            return i;
        right = right - arr[i];
        left = left + arr[i];
    }
    
    return -1;
}

int main()
{
    vector<int> arr = {1,3,5,2,2};

    cout << solve(arr) << endl;

    return 0;
}