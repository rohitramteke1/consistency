#include <bits/stdc++.h>
using namespace std;

void convertToWave(int n, vector<int>& arr) {

    for (int i = 0; i < n-1; i+=2)
        swap(arr[i], arr[i+1]);
    
    for (auto &&i : arr)
        cout << i << ' ';
    
}

int main()
{
    vector<int> arr = {2,4,7,8,9,10};
    //  4 2 8 7 10 9
    int n = 6;
    convertToWave(n, arr);


    return 0;
}