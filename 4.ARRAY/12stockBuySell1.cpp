#include <bits/stdc++.h>
using namespace std;

// Question says that you can purchase one stock and sell it 
// only one stock.... Remeber it

int brute(vector<int> &arr) {
    int n = arr.size();
    int profit = 0;

    int minSoFar = arr[0];

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            profit = max(profit, arr[j] - arr[i]);
        }
    }

    return profit;
}

// best time to buy and sell stock - I
int better(vector<int> &arr) {
    int n = arr.size();
    int profit = 0;

    int minSoFar = arr[0];

    for (int i = 1; i < n; i++)
    {
        int curr_profit = arr[i] - minSoFar;
        profit = max(profit, curr_profit);
        minSoFar = min(minSoFar, arr[i]);
    }

    return profit;
}



int main()
{
    vector<int> stock = {1,5,3,8,12};
    cout << brute(stock) << endl;
    return 0;
}