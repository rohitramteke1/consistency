#include <bits/stdc++.h>
using namespace std;
class Practical{
    vector<int> nums;
public:
    Practical(vector<int> nums) {
        this->nums = nums;
    }
    int partition(int low, int high) {

        int pi = low;

        while(low < high) {
            while(nums[pi] >= nums[low]) 
                low++;
            while(nums[pi] < nums[high])
                high--;
            if(low < high)
                swap(nums[low], nums[high]);
        }

        swap(nums[pi], nums[high]);

        return high;
    }
    void quickSort(int low, int high) {
        if(low < high) {
            int mid = partition(low, high);
            quickSort(low, mid);
            quickSort(mid + 1, high);
        }
    }
    void print() {
        for (auto &&i : nums)
            cout << i << ' ';
    }
};

int main()
{
    vector<int> nums = {7,8,9,10,0,1,2,3,4,5};
    Practical p(nums);

    p.quickSort(0, 9);

    p.print();

    return 0;
}