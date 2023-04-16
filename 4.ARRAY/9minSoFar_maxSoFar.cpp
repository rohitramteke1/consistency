#include <bits/stdc++.h>
using namespace std;

// O(N^2) + O(1)
int brute(vector<int> &arr) {
    int n = arr.size();
    int profit = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            profit = max(profit, arr[j] - arr[i]);

    return profit;
}

// O(N) + O(N)
int better(vector<int> &arr) {
    int profit = 0;
    int n = arr.size();
    vector<int> prefix(n, 0);

    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = min(prefix[i-1], arr[i]);
        profit = max(profit, arr[i] - prefix[i]);
    }

    // 8 3 5 13 3 12
    // 8 3 3  3 3  3

    return profit;
}

// O(N) + O(1)
int16_t solve(vector<int> &arr) {
    int n = arr.size();
    int minSoFar = arr[0];
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        // imagine in this way, let say we're selling our stock at
        // ith day, then upto that ith day, we purchase some stock at some low cost
        // right ? 
        int diff = arr[i] - minSoFar;

        profit = max(profit, diff);

        // update the minSoFar
        minSoFar = min(minSoFar, arr[i]);
    }
    return profit;
}

int main()
{
    vector<int> arr = {8,3,5,13,3,12};

    cout << solve(arr) << endl;
    cout << brute(arr) << endl;
    cout << better(arr) << endl;

    return 0;
}