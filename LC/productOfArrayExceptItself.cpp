#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> &arr, int n) {
    int prod = 1;
    int flag = 0;

    for (auto &&i : arr)
    {
        if(i == 0)
            flag++;
        else
            prod *= i;
    }

    for (int i = 0; i < n; i++)
    {
        if(flag == 1 && arr[i] != 0) {
            arr[i] = 0;
        } 
        else if(flag == 1 && arr[i] == 0) {
            arr[i] = prod;
        }
        else if(flag > 1) {
            arr[i] = 0;
        }
        else { // flag == 0
            arr[i] = prod / arr[i];
        }
    }
}

int main()
{
    vector<int> arr = {10, 3, 5, 6, 2};
    solution(arr, arr.size());
    for (auto &&i : arr)
    {
        cout << i << ' ';
    }
    
    return 0;
}