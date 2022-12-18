#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr) {
    int i = 0;
    int j = 0;
    int k = arr.size()-1;
    while (j <= k) {
        if(arr[j] == 0) {
            if(arr[i] != arr[j]) swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if(arr[j] == 1) {
            j++;
        }
        else if(arr[j] == 2) {
            if(arr[j] != arr[k]) swap(arr[j], arr[k]);
            k--;
        }
    }
}

void sort012switch(vector<int> &arr) {
    int i = 0;
    int j = 0;
    int k = arr.size()-1;
    while (j <= k) {
        switch (arr[j])
        {
        case 0:
            if(arr[i] != arr[j]) 
                swap(arr[i], arr[j]);
            i++; j++;
            break;
        case 1: 
            j++;
            break;
        case 2:
            if(arr[j] != arr[k]) swap(arr[j], arr[k]);
                k--;
            break;
        }
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 2, 1, 0};
    // sort012(arr);
    sort012switch(arr);
    for (auto &&i : arr) cout << i << ' ';
    
    return 0;
}