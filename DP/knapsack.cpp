#include <bits/stdc++.h>
using namespace std;

// w -> capacity of knapsack
// wt -> weight arr
// val -> corresponding weight's value arr
// n -> size

// only recursive calls -> no DP is being used
int knapsack(int wt[], int val[], int n, int w)
{
    if (n == 0 || w == 0)
        return 0;

    // choice diagram <code>
    // if the ith-weight is <= weight then -> we've two choices
    // inlcude it, or not and pick up the max among the choices.
    if (wt[n - 1] <= w)
        return max(
            val[n - 1] + knapsack(wt, val, n - 1, w - wt[n - 1]),
            knapsack(wt, val, n - 1, w));

    // if (wt[n - 1] > w)
    else
        return knapsack(wt, val, n - 1, w);

}

int main()
{
    int wt[] = {1,2,3,4,5,6};
    int val[] = {6,5,4,3,2,1};

    cout << knapsack(wt, val, 6, 10) << endl ;

    return 0;
}