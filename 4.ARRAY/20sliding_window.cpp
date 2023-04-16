#include <bits/stdc++.h>
using namespace std;

int slidingWindow(vector<int> &arr, int k) {

    int n = arr.size();
    int window = 0;
    
    if( k > n)
        return INT_MIN;

    // create a window of size k
    for (int i = 0; i < k; i++)
        window += arr[i];
    
    // then do something on space to avoid the extra loop
    int maxSum = window;

    // now, slide the window
    for (int i = k; i < n; i++)
    {
        window -= arr[i-k];
        window += arr[i];
        maxSum = max(maxSum, window);
    }
    
    return maxSum;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    cout << slidingWindow(arr, 3) << endl;
    return 0;
}