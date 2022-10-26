#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++)
    {
        int flag = false;
        for (int j = 0; j < size-i-1; j++)
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = true;
            }

        if (!flag) break;
    }   
}

int main()
{
    // int arr[] = {9,4,5,6,30,1,5};
    int arr[] = {1,2,3,4,5,6,7};
    // 9 4 5 6 30 1 5 => 6
    // 4 5 6 9 1 5 30 => 5
    // 4 5 6 1 5 9 30 => 4
    // 4 5 1 5 6 9 30 => 3
    // 4 1 5 5 6 9 30 => 2
    // 1 4 5 5 6 9 30 => 1
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);
    for (auto i : arr)
        cout << i << ' ';    
    
    return 0;
}