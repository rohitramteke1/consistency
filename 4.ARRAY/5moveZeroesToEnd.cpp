#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEnd(vector<int> &arr) {

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0) {
            for (int j = i+1; j < n; j++)
            {

                if(arr[j] != 0)
                {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
    for (auto &&i : arr)
    {
        cout << i << ' ';
    }
}


void optimal(vector<int> &arr) {
    int n = arr.size();
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for (auto &&i : arr)
    {
        cout << i << ' ';
    }
}

int main()
{
    vector<int> arr = {10,5,0,0,8,0,9,0};
    // moveZeroesToEnd(arr);
    optimal(arr);
    
    return 0;
}