#include <bits/stdc++.h>
using namespace std;

// Given an array A of positive integers. Your task is to find the leaders in the array. 
// An element of array is leader if it is greater than or equal to all 
// the elements to its right side. The rightmost element is always a leader. 

void brute(vector<int> &arr) {
    int n = arr.size();

    int leader = arr[n-1];

    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = i+1; j < n; j++)
        {
            if(arr[i] <= arr[j]) {
                flag = true;
                break;
            }
        }
        if(flag == false) {
            cout << arr[i] << ' ';
        }
    }
}

void leaders(vector<int> &arr) {
    int n = arr.size();
    int leader = arr[n-1];
    int i = n-2;
    for (; i >= 0; --i)
    {
        if(leader <= arr[i]) {
            cout << leader << ' ';
            leader = arr[i];
        }
    }
    cout << leader << endl;
}

int main()
{
    // vector<int> arr = {16,17,4,3,5,2};
    vector<int> arr = {30,20,10};
    // leaders(arr);
    brute(arr);
    
    return 0;
}