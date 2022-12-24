#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int i = 0, j = 0;
    int curr = 0;
    while( i < nums.size() )
    {
        curr += nums[i];
        if(i < k) {
            i++;
            continue;
        }
        else {
            curr = curr - nums[j];
            i++; j++;
        }
    }
    cout << curr << endl;
    
    return 0;
}