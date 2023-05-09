#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;

    // Base case: If there is only one element in the array
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // Base case: If there are two elements in the array
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.min = arr[high];
            result.max = arr[low];
        }
        else {
            result.min = arr[low];
            result.max = arr[high];
        }
        return result;
    }

    // Divide the array into two halves and recursively call getMinMax()
    mid = (low + high) / 2;
    left = getMinMax(arr, low, mid);
    right = getMinMax(arr, mid + 1, high);

    // Merge the results
    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Pair result = getMinMax(arr, 0, n - 1);
    printf("Minimum element in the array is %d\n", result.min);
    printf("Maximum element in the array is %d\n", result.max);
    return 0;
}
