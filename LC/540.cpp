#include <bits/stdc++.h>
using namespace std;

// Brute Force O(N) + O(1)
int singleNonDuplicateBrute(vector<int> &nums) {
    int x = 0;
    for(auto &&i : nums) x ^= i;
    return x;
}

// Optimal O(logN)
int singleNonDuplicate(vector<int> &nums) {
    // edge cases
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = nums.size();
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];
    int low = 0;
    int high = n-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(mid - 1 >= 0 && mid + 1 <= n-1) {
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            if(nums[mid] == nums[mid - 1] ) {
                int len = mid - low + 1;
                if(len & 1) {
                    high = mid;
                }
                else {
                    low = mid + 1;
                }
            }
            if(nums[mid] == nums[mid + 1]) {
                int len = high - mid + 1;
                if(len & 1) {
                    low = mid;
                }
                else {
                    high = mid - 1;
                }
            }
        }
    }
    
    return -1;
}


// Optimal O(logN)
int singleNonDuplicateCleanCode(vector<int> &nums) {
    // edge cases
    int n = nums.size();
    if(n == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];
    int low = 0;
    int high = n-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(mid - 1 >= 0 && mid + 1 <= n-1) {
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            if(((mid % 2 == 1) && nums[mid] == nums[mid - 1]) || ((mid % 2 == 0) && nums[mid] == nums[mid + 1]) ) {
                low = mid + 1;
            }
            else 
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(nums) << endl;
    cout << singleNonDuplicateCleanCode(nums) << endl;
    
    return 0;
}