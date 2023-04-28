// https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1

#include <iostream>
#include <vector>

using namespace std;

// idea is to store the 2 values in one place

// Dividend = (Quotient * Divisor) + Remainder

void rearrange_array(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = (arr[ arr[i] ] % n) * n + arr[i];
    for (int i = 0; i<n; i++) {
        arr[i] /= n;
    }
}

int main() {
    int nums[] = {4, 0, 2, 1, 3};
    int n = sizeof(nums)/sizeof(nums[0]);

    rearrange_array(nums, n);

    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
