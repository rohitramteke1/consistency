#include <bits/stdc++.h>
using namespace std;

// best time to buy and sell stock - III Hard
int optimal(vector<int> &arr) {
    
    int profit = 0;
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        if(arr[i] > arr[i-1])
            profit += arr[i] - arr[i-1];
    }
    
    return profit;
}

int multiply(int a, int b)
{
    return a*b;
}

// GFG Failed Solution
int brute(vector<int> &arr, int start, int end) {

    if(end <= start)
        return 0;

    int profit = 0;

    for (int i = start; i < end; i++)
    {
        for (int j = i+1; j <= end; j++)
        {
            if(arr[j] > arr[i]) {
                int curr_profit = arr[j] - arr[i] + brute(arr, start, j-1) + brute(arr, j+1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    
    return profit;
}

int main()
{
    vector<int> stock = {1,5,3,8,12};
    cout << brute(stock, 0, 4) << endl;

    return 0;
}