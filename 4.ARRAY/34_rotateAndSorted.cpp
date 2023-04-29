#include <bits/stdc++.h>
using namespace std;

bool checkSortedAndRotated(int *arr, int n) {
    int count = 0;
    for (int i = 1; i < n; i++)
        if (arr[i-1] > arr[i])
            count++;

    return count <= 1;
}

int main()
{
    int arr[] = {1,1,1}; //  {1,2,3,4,5}
    int n = 3;
    cout << checkSortedAndRotated(arr, n) << endl ;
    return 0;
}