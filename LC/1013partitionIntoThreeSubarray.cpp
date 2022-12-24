#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {0,2,1,-6,6,-7,9,1,2,0,1};
    int prefSum = 0;
    int suffSum = accumulate(arr.begin(), arr.end(), 0);
    for (auto &&i : arr)
    {
        prefSum += i;
        cout << prefSum << ' ';
    }
    cout << endl;
    for (auto &&i : arr)
    {
        cout << suffSum << ' ';
        suffSum = suffSum - i;
    }
    
    
    
    return 0;
}