#include <bits/stdc++.h>
using namespace std;

double findMediumSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // first array must be smaller
    if (nums2.size() < nums1.size())
        return findMediumSortedArrays(nums2, nums1);
    
    int n1 = nums1.size();
    int n2 = nums2.size();

    // why high = n1 not n1-1, because we can add the cut beyond the n1
    // n1 + n2 is odd then
    // n1 + 1 is the medium else n1th + n2th is medium
    int low = 0, high = n1;
    
    while (low <= high) {

        int cut1 = (low + high) >> 1;
        int cut2 = (n1 + n2 + 1) >> 1 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            int a = min(right1, right2);
            int b = max(left1, left2);

            if ( (n1 + n2) % 2 == 0 ) 
                return (double)( a + b ) / 2.0;
            else
                return (double)(b);
        }
        else if ( left1 > right2 )
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
}

int main()
{
    vector<int> nums1 = {2,4,6};
    vector<int> nums2 = {1,3}; // 1 2 3 4 6
    
    cout << findMediumSortedArrays(nums1, nums2) << endl;
    
    return 0;
}