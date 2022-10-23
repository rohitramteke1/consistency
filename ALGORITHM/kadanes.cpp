// maximum subarray sum
// Kadane's algorithm

#include <bits/stdc++.h>
using namespace std;

// kadanes algo doesn't work if we've all elements are negative
// even if you want to handle the above limitation we can simply
// return the max of negative arr;
int kadanesAlgorithm(vector<int> v) {
    int curSum = 0;
    int maxSum = INT_MIN;

// NOTE: kadanes algo limitation handling -> simply return the max(negative_arr);
    // int index = v.size()-1;
    // bool flag = false;
    // while (index != -1)
    // {
    //     v[index--] < 0 ? flag = true : flag = false;
    // } if(index == -1 && flag == true) return *max_element(v.begin(), v.end());
    
    int last_index = -1;
    int first_index = 0;
    for (int i = 0; i < v.size(); i++)
    {     
        curSum += v[i];
        if(curSum > maxSum) {
            maxSum = curSum;
            last_index = i;
            first_index++;
        }
        if(curSum < 0) {
            curSum = 0;
        }
    }
    cout << first_index+1 << ' ' << last_index << endl ;
    return maxSum;
}

int main()
{
    // vector<int> arr = {1,-2,3,6,-9,8,4,-5};
    // vector<int> arr = {-11,-9,-5,-5,-9}; // invalid -> according to wikipedia
    vector<int> arr;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        arr.emplace_back(a);
    }
    
    int maximumSubArraySum = kadanesAlgorithm(arr);
    cout << maximumSubArraySum << endl;
    
    return 0;
}