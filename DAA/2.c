#include <stdio.h>

int arr[100];

void swap(int low, int high)
{
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

int partition(int low, int high) {
    int pi = low;
    while(low < high) {
        while(arr[pi] >= arr[low])
            low++;
        while(arr[pi] < arr[high])
            high--;
        if(low < high)
            swap(low, high);
    }

    swap(pi, high);

    return high;
}

void quickSort(int low, int high) {
    if(low < high) {
        int pi = partition(low, high);
        quickSort(low, pi);
        quickSort(pi + 1, high);
    }
}

int main() {

    // add elements to the array
    for (int i = 0; i < 6; i++)
        arr[i] = 6-i;

    int n = 6;

    // call the function
    quickSort(0, n-1);

    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}