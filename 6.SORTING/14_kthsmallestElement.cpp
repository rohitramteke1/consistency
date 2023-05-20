#include <iostream>
using namespace std;

int lomuto(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j=low; j <= high-1; ++j) {
        if (pivot >= arr[j]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthSmallestElement(int arr[], int low, int high, int k) {
    while (low <= high) {
        int pi = lomuto(arr, low, high);
        if (pi == k-1)
            return arr[pi];
        else if (pi > k-1)
            high = pi - 1;
        else
            low = pi + 1;
    }
    return -1;
}

int main() {
    int arr[] = {7,10,4,3,20,15};
    // 0 1 2 4 6 9
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << kthSmallestElement(arr, 0, n-1, 3) << endl;
    

    return 0;
}