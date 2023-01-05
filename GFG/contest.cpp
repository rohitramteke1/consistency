#include <bits/stdc++.h>
using namespace std;

int countOnes(vector<int> & arr, int l, int r) {
    cout << l << ' ' << r << endl;
    int leftOnes = 0;
    int rightOnes = 0;
    while(l >= 0 && arr[l] == 1) {
        leftOnes++;
        l--;
    }
    while(r < arr.size() && arr[r] == 1) {
        rightOnes++;
        r++;
    }
    return leftOnes + rightOnes;
}

int solve(vector<int> & arr) {
    int curr = 0;
    int len = 0;
    int ii = 0;
    int jj = -1;
    for(int i=0; i<arr.size(); ++i) {
        if(arr[i] == 0) {
            curr++;
        }
        else {
            if(len <= curr) {
                ii = i-1;
                // len = i - j + 1; sliding-window-len
                jj = i - curr;
                len = curr;
            }
            curr = 0;
        }
    }
    cout << jj << ' ' << ii << endl;
    // int x = countOnes(arr, jj-1, ii+1);
    // cout << x << endl;

    // return ii - jj + x;
    return 0;
}

int main()
{
    vector<int> arr = {0,0,1,1,0,1,1,1};
    cout << solve(arr) << endl;

    return 0;
}