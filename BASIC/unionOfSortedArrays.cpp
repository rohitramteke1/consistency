#include <bits/stdc++.h>
using namespace std;

void unionOfArrays(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    vector<int> v;
    while(i < m && j < n) {
        if(arr1[i] < arr2[j]) {
            // if(*(v.end()-1) != arr1[i])
            // {
                v.push_back(arr1[i]);
                i++;
            // }
        }
        else if(arr1[i] > arr2[j]) {
            // if(*(v.end()-1) != arr2[j])
            // {
                v.push_back(arr2[j]);
                j++;
            // }
        }
    }
    for (auto &&i : v)
    {
        cout << i << ' ';
    }
    
}

int main()
{
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1,2,3};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    unionOfArrays(arr1, arr2, m, n);
    return 0;
}