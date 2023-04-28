#include <iostream>

void rearrangeArray(int arr[], int n) {
    int max_index = n-1;
    int min_index = 0;
    int mx = arr[n-1] + 1;

    // logic is simple store the two values at the one index
    for (int i=0; i<n; i++) {
        // even index
        if ( i % 2 == 0 ) {
            arr[i] = (arr[max_index] % mx) * mx + arr[i];
            max_index--;
        }
        // odd index
        else {
            arr[i] = (arr[min_index] % mx) * mx + arr[i];
            min_index++;
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] / mx;
    
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Original array: ";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";

  rearrangeArray(arr, n);

  std::cout << "\nRearranged array: ";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";

  return 0;
}