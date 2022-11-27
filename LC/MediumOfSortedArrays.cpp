#include <bits/stdc++.h>
using namespace std;

double mediumOfTwoSortedArrays(vector<int> nums1, vector<int> nums2) {

    vector<int> merged_vector( (nums1.size() + nums2.size() ));

    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged_vector.begin() );

    // for (auto &&i : merged_vector)
    //     cout << i << ' ';
    // cout << endl;
    // int s = merged_vector.size();

    if(s%2 == 0)
        return double(merged_vector[s/2-1] + merged_vector[s/2]) / 2;
    return double(merged_vector[s/2]);
}

int main()
{
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};
    cout << mediumOfTwoSortedArrays(nums1, nums2);
    
    return 0;
}