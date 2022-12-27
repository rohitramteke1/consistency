#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == arr[mid])
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            low = mid + 1;
        }
        else
        { // target > arr[mid]
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
    cout << binarySearch(arr, 11, 0) << endl;

    return 0;
}