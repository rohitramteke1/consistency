#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int nums[], int low, int high) {
    int pivot = nums[low];
    int i = low - 1;
    int j = high + 1;
    
    while(1) {
        do {
            i++;
        } while(nums[i] < pivot);

        do {
            j--;
        } while(nums[j] > pivot);

        if(i >= j) {
            return j;
        }

        swap(&nums[i], &nums[j]);
    }
}

void quickSort(int nums[], int low, int high) {
    if(low < high) {
        int pi = partition(nums, low, high);
        quickSort(nums, low, pi);
        quickSort(nums, pi + 1, high);
    }
}

void printArray(int nums[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
}

int main() {
    int nums[] = {7, 8, 9, 10, 0, 1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Array elements before QuickSort: ");
    printArray(nums, size);

    quickSort(nums, 0, size - 1);

    printf("\nAfter QuickSort: ");
    printArray(nums, size);

    return 0;
}
