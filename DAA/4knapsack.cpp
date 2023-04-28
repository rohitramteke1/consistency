#include <bits/stdc++.h>
using namespace std;

// Greedy Fractional Knapsack

struct Item {
    double profit;
    double weight;
};

bool cmp(Item a, Item b) {
    double r1 = double(a.profit) / double(a.weight);
    double r2 = double(b.profit) / double(b.weight);
    return r2 < r1;
}

// O(NlogN)
double knapsack(Item arr[], int n, int wt) {
    double res = 0;
    int curr_weight = 0;

    // sort in the descending order
    sort(arr, arr + n, cmp);
    
    for (int i = 0; i < n; i++)
    {
        if(curr_weight + arr[i].weight <= wt) {
            // take the whole object
            curr_weight += arr[i].weight;
            res += arr[i].profit;
        }
        else {
            int remaining = wt - curr_weight;
            // now take the fraction of the object
            res += (arr[i].profit / (double)arr[i].weight) * (double)remaining;
            break;
        }
    }

    return res;
}

int main()
{   
    int n, wt;
    cout << "Enter the no of objects: "; cin >> n;
    cout << "Enter the weight and profit of each object: ";
    struct Item arr[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i].weight = a;
        arr[i].profit = b;
    }
    
    cout << "Now Enter the capacity of knapsack: "; cin >> wt;
    
    cout << "Fractional Knapsack maximum profit: ";

    cout << knapsack(arr, n, wt) << endl;

    return 0;
}