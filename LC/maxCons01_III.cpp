#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> & arr, int k) {
    int i = 0;
    int j = 0;
    int len = 0;
    int zero = 0;
    while(i < arr.size()) {

        if(arr[i] == 0) {
            zero++;
        }
        while(zero > k) {
            if(arr[j] == 0) {
                zero--;
            }
            j++;
        }
        // int currLen = i - j + 1;
        len = max(len, i - j + 1);
        i++;
    }
    return len;
}

int main()
{
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    cout << solve(arr, 2);
    
    return 0;
}