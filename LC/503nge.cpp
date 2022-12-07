#include <bits/stdc++.h>
using namespace std;

void bfs_nge(vector<int> &nums)
{
    int n = nums.size();
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                flag = true;
                cout << nums[j] << ' ';
                break;
            }
        }
        if (!flag) cout << -1 << ' ';
    }
}

void ngeI(vector<int> &nums)
{
    stack<int> s;
    vector<int> v(nums.size());
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {   
        while (!s.empty() && s.top() <= nums[i]) s.pop();
        if (s.empty()) v[i] = -1;
        else if(!s.empty() && s.top() > nums[i]) v[i] = s.top();
        s.push(nums[i]);
    }
    for (auto &&i : v) cout << i << ' ';
}

void ngeII(vector<int> &nums)
{
    stack<int> s;
    int n = nums.size();
    vector<int> v(n);
    for (int i = 2*n - 1; i >= 0; i--)
    {   
        while (!s.empty() && s.top() <= nums[i%n]) s.pop();
        if(i < n) {
            if(!s.empty()){
                v[i] = s.top();
            } else {
                v[i] = -1;
            }
        }
        s.push(nums[i%n]);
    }
    for (auto &&i : v) cout << i << ' ';
}

int main()
{
    vector<int> nums = {3, 10, 4, 2, 1, 2, 6, 7, 2, 9};

    // ngeI(nums);
    // cout << endl;
    // ngeII(nums);
    // cout << endl;
    // bfs_nge(nums);

    return 0;
}