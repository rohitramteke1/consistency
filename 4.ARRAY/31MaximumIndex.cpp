#include <bits/stdc++.h>
using namespace std;

int maximumIndex(int *arr, int n) {

    vector<int> leftMin(n, 0);
    vector<int> rightMax(n, 0);
    
    leftMin[0] = arr[0];
    for (int i = 1; i < n; i++)
        leftMin[i] = max(leftMin[i-1], arr[i]);
        
    rightMax[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
        rightMax[i] = max(rightMax[i+1], arr[i]);


    int maxIndex = -1;
    int i = 0, j = 0;
    while ( i < n && j < n) {
        if ( leftMin[i] <= rightMax[j] ) {
            maxIndex = max(maxIndex, j - i);
            j++;
        } 
        else
            i++;
    }

    return maxIndex;
}

int main()
{
    int n = 9;
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    cout << maximumIndex(arr, n) << endl;

    return 0;
}