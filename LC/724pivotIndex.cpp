#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1,7,3,6,5,6};
    int n = arr.size();

    // vector<int> pref(n + 1 , 0);
    // vector<int> suff(n + 1 , 0);

    int pSum = 0;
    int sSum = accumulate(arr.begin(), arr.end(), 0);
    

    // for (int i = 0; i < n; i++)
    // {
    //     pref[i+1] = pref[i] + arr[i];
    //     suff[n-i-1] = suff[n-i] + arr[n-i-1];
    // }

    // for (auto &&i : pref)
    // {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (auto &&i : suff)
    // {
    //     cout << i << ' ';
    // }
    
    

    for (int i = 0; i < n; i++)
    {
        pSum += arr[i];
        // cout << sSum << ' ';
        if(pSum == sSum) {
            cout << i << endl;
        }
        sSum -= arr[i];
    }
    
    return 0;
}