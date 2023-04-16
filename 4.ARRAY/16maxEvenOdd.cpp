#include <bits/stdc++.h>
using namespace std;

// O(N) + O(1)
int kadanes(vector<int> &arr) {
    int n = arr.size();
    int res = 1;
    int len = 1;

    for (int i = 0; i < n; i++)
    {
        if( (arr[i-1] & 1) && ( !(arr[i] & 1) ) or 
            !(arr[i-1] & 1) && ( (arr[i] & 1) ) ) {
            len++;
        } else {
            res = max(res, len);
            len = 1;
        }
    }
    
    return res;
}

// My Solution
int maxEvenOddLen(vector<int> &arr) {
    int n = arr.size();
    int count = 1;
    int len = 0;
    bool flag = arr[0] & 1;

    for (int i = 1; i < n; i++)
    {
        if( (arr[i] & 1) == flag) {
            flag = !flag;
            count++;
        } else {
            len = max(count, len);
            flag = ! (arr[i] & 1) ;
            count = 1;
        }
    }

    return max(count, len);
}

int main()
{
    vector<int> arr = {9,4,2,10,7,8,8,1,9};    
    // vector<int> arr = {10, 12, 14, 7, 8}; 

    cout << maxEvenOddLen(arr) << endl;
    cout << kadanes(arr) << endl;

    return 0;
}