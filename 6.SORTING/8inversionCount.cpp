#include <bits/stdc++.h>
using namespace std;


// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Solution - 1
// Brute Force
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        int n = N;
        int inversionCount = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (arr[i] > arr[j]) 
                    inversionCount += 1;
            }
        }
        return inversionCount;
    }
};

// Optimal 
// Solution - 2
// O(NLogN)
long long merge(int arr[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    long long countInversion = 0;

    vector<int> temp;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right] ) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            countInversion += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;   
    }

    // copy to the original array

    for (int i=low; i<= high; i++) {
        arr[i] = temp[i - low];
    }
    return countInversion;
}

long long mergeSort(int arr[], int low, int high) {
    if (low < high) {
        long long countInversion = 0;
        int mid = low + ( (high - low) >> 1);

        countInversion += mergeSort(arr, low, mid );
        countInversion += mergeSort(arr, mid + 1, high);

        countInversion += merge(arr, low, mid, high);

        return countInversion;
    }
    return 0;
}

long long countInversionOptimal(int arr[], int n) {
    return mergeSort(arr, 0, n-1);
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    cout << countInversionOptimal(arr, 5) << endl ;
    return 0;
}