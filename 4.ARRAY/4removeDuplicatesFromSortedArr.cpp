#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr) {
    for (auto &&i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void removeDuplicates(vector<int> &arr) {
    print(arr);
    
    int i = 0;
    int n = arr.size();
    
    for (int j = 1; j < n; j++)
    {
        if(arr[j-1] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }

    print(arr);
}

int main()
{
    vector<int> arr = {1,1,2,3,3,4,5,5,5};
    removeDuplicates(arr);
    
    return 0;
}