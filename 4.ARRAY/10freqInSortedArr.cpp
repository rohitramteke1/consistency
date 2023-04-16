#include <bits/stdc++.h>
using namespace std;

// O(N) + O(1)
void brute(vector<int> &arr) {
    int n = arr.size();
    int count = 1;
    int i = 1;
    while(i < n) {
        while(i+1 < n && arr[i-1] == arr[i]) {
            count++;
            i++;
        }
        cout << arr[i-1] << ' ' << count << endl;
        count = 1;
        i++;
    }
    cout << arr[i-1] << ' ' << count << endl;
}

// O(N) + O(1)
void freqOfSortedArray(vector<int> &arr) {
    int n = arr.size();
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i-1] == arr[i])
            count++;
        else {
            cout << arr[i-1] << ' ' << count << ' ' << endl;
            count = 1;
        }
    }
    cout << arr[n-1] << ' ' << count << endl;
}

int main()
{
    vector<int> arr = {10,10,10,30,30,40};
    // freqOfSortedArray(arr);
    brute(arr);
    return 0;
}