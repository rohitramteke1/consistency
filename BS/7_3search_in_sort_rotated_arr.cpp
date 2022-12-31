#include <bits/stdc++.h>
using namespace std;
// Adobe Amazon BankBazaar D-E-Shaw FactSet Flipkart Hike Intuit MakeMyTrip 
// Microsoft Paytm Snapdeal Times-Internet Google
int findMin(int arr[], int n) {
    int low = 0;
    int high = n-1;
    while(low <= high) {
        if(arr[low] <= arr[high]) return low;
        int mid = low + (high - low)/2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
        if(arr[low] <= arr[high]) return arr[low];
        if(arr[mid] <= arr[prev] && arr[mid] <= arr[high]) {
            return mid;
        }
        if(arr[low] <= arr[mid]) {
            low = mid + 1;
        }
        else if(arr[mid] <= arr[high]) {
            high = mid - 1;
        }
    }
    
    return arr[0];
}

int binarySearch(int arr[], int low, int high, int key) {
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == key) {
            return mid;
        }
        else if(key > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int search(int A[], int l, int h, int key){
    int index = findMin(A, h+1);
    int ans = binarySearch(A, l, index-1, key); // left half
    if(ans != -1) return ans;
    ans = binarySearch(A, index, h, key); // right half
    return ans;
    
    // for(int i=0; i<h+1; i++) {
    //     if(A[i] == key) return i;
    // }
    // return -1;
}


int main()
{
    int N = 9;
    int A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 10;
    cout << search(A, 0, N-1, key) << endl;
    return 0;
}