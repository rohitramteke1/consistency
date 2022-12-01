#include <bits/stdc++.h>
using namespace std;

int duplicate(int arr[], int n) {
    // hare and tortoise || floyd cycle detection
    int slow = arr[0];
    int fast = arr[0];

    // detect a cycle or node or same element
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    while(slow != fast);

    // reset the slow || arr[0]
    slow = arr[0];
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main()
{
    int arr[] = {1,3,4,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << duplicate(arr, n ) << endl;
    
    return 0;
}