#include <bits/stdc++.h>
using namespace std;

// failed, i'll come back tommorow
int len(int digit) {
    int k = 0;
    while(digit) {
        k++;
        digit /= 10;
    }
    return k;
}

vector<int> addToArrayForm(vector<int>& num, int k) {
    reverse( begin(num), end(num) );

    int m = len(k);
    int n = num.size();
    vector<int> v;

    int i = 0, j =  0;
    int carry = 0, digit = 0;

    while( i < m || j < n) {
        int num1 = 0, num2 = 0;
        if(i < m) {
            num1 = k % 10;
            i++;
            k = k / 10;
        }
        if(j < n) {
            num2 = num[j];
            j++;
        }
        digit = num1 + num2 + carry;
        carry = digit / 10;
        num[j] = (digit % 10);
    }
    if(carry)
        num.emplace_back(carry);    

    reverse( begin(num), end(num) );
    return num;
}

vector<int> solve(vector<int> &nums, int k) {
    int n = nums.size() - 1;
    for (int i = n; i >= 0 && k; --i)
    {
        nums[i] = k + nums[i]; 
        k = nums[i] / 10;
        nums[i] = nums[i] % 10;
    }
    while (k)
    {
        nums.insert(nums.begin(),k % 10);
        // nums.emplace_back(k % 10);
        k = k / 10;
    }
    return nums;
}

int main()
{
    vector<int> num = {2,7,4};
    int k = 181;
    vector<int> v = solve(num, k);
    
    for (auto &&i : v)
        cout << i << ' ';
    // solve(num, k);

    return 0;
}