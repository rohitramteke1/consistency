#include <bits/stdc++.h>
using namespace std;

int maximumSubArraySum(vector<int> &arr) {
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
        if(sum > maxi) {
            maxi = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }

    return maxi;
}

int main()
{
    vector<int> arr = {4,1, -1, 9};
    cout << maximumSubArraySum(arr) << endl;
    return 0;
}