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
        else if (target > arr[mid])
        {
            low = mid + 1;
        }
        else
        { // target < arr[mid]
            high = mid - 1;
        }
    }
    return -1;
}

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
        else if (target >= arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 4, 4, 4, 8, 9, 10};
    int fo = firstOccurence(arr, 11, 11);
    int lo = lastOccurence(arr, 11, 11);
    if(fo == -1 || lo == -1)
        cout << 0 << endl;
    else 
    {
        int len = lo - fo + 1;
        cout << len << endl;
    }

    return 0;
}