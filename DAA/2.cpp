#include <bits/stdc++.h>
using namespace std;
class Practical{
    vector<int> nums;
    int _max, _min;
public:
    Practical(vector<int> nums) {
        this->nums = nums;
        _max = _min = 0;
    }
    
    // O(3n/2-2) + O(logH)
    void max_min(int low, int high) {
        int mid;
        if(low == high)
            _max = _min = nums[low];
        else if(low = high - 1)
        {
            _max = max(nums[low], nums[high]);
            _min = min(nums[low], nums[high]);
        }
        else {
            int temp_max, temp_min;
            mid = low + (high - low)/2;
            // first half call
            max_min(low, mid);
            // at the first call, the instance variable contains min-max of first half
            // later on second call they'll be overridden by second half, 
            // that's why we're storing them.
            temp_max = _max;
            temp_min = _min;
            // right-half call
            max_min(mid+1, high);
            _max = max(_max, temp_max);
            _min = max(_min, temp_min);
        }
    }

    void print(int low, int high) {
        max_min(low, high);
        cout << "\nMax of array: " << _max << '\n' << "Min of array: "<< _min << endl;
    }

};

int main()
{
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10};
    cout << "Array elements are: ";
    for (auto &&i : nums)
        cout << i << ' ';
    
    Practical p(nums);
    p.print(0, nums.size());

    return 0;
}