#include <iostream>
#include <vector>
using namespace std;


// not working
void stockBuySell(int prices[], int n) {
    // vector<pair<int, int>> intervals; // vector to store the intervals
    // int i = 0;
    // while (i < n - 1) {
    //     while ((i < n - 1) && (prices[i + 1] <= prices[i])) // skip until price increases
    //         i++;
    //     if (i == n - 1) // if we have reached the end
    //         break;
    //     int buy = i++; // set buy day
    //     while ((i < n) && (prices[i] >= prices[i - 1])) // skip until price decreases
    //         i++;
    //     int sell = i - 1; // set sell day
    //     intervals.push_back(make_pair(buy, sell)); // add interval to vector
    // }
    // if (intervals.empty()) // if there are no profitable intervals
    //     cout << "No Profit";
    // else {
    //     for (auto interval : intervals)
    //         cout << "(" << interval.first << " " << interval.second << ") ";
    // }
}

int main() {
    int prices[] = { 100, 180, 260, 310, 40, 535, 695 };
    int n = sizeof(prices) / sizeof(prices[0]);
    stockBuySell(prices, n);
    return 0;
}
