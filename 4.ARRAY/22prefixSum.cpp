#include <bits/stdc++.h>
using namespace std;

int getSum(vector<int> &nums, int i, int j) {
    return nums[j] - nums[i];
}

int main()
{
    vector<int> prefix = {2,8,3,9,6,5,4};

    int n = prefix.size();
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i] + prefix[i-1];
    
    cout << getSum(prefix, 0, 2) << endl;
    cout << getSum(prefix, 1, 3) << endl;
    cout << getSum(prefix, 2, 6) << endl;

    return 0;
}