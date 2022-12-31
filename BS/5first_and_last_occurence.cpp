#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int n , int target) {
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == arr[mid])
        {
            ans = mid;
            high = mid-1;
        }
        else if (target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int lastOccurence(int arr[], int n , int target) {
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == arr[mid])
        {
            ans = mid;
            low = mid+1;
        }
        else if (target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 4, 4, 4, 8, 9, 10};
    cout << firstOccurence(arr, 11, 4) << endl;
    cout << lastOccurence(arr, 11, 4) << endl;

    return 0;
}