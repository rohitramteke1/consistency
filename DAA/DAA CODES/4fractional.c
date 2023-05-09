#include <stdio.h>
#include <stdlib.h>

// Greedy Fractional Knapsack

typedef struct {
    double profit;
    double weight;
} Item;

int cmp(const void *p1, const void *p2) {
    Item *a = (Item *)p1;
    Item *b = (Item *)p2;
    double r1 = a->profit / a->weight;
    double r2 = b->profit / b->weight;
    if (r2 > r1) {
        return 1;
    } else if (r2 < r1) {
        return -1;
    } else {
        return 0;
    }
}

// O(NlogN)
double knapsack(Item arr[], int n, int wt) {
    double res = 0;
    int curr_weight = 0;

    // sort in the descending order
    qsort(arr, n, sizeof(Item), cmp);
    
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
            res += (arr[i].profit / arr[i].weight) * remaining;
            break;
        }
    }

    return res;
}

int main()
{   
    int n, wt;
    printf("Enter the no of objects: ");
    scanf("%d", &n);
    printf("Enter the weight and profit of each object: ");
    Item arr[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[i].weight = a;
        arr[i].profit = b;
    }
    
    printf("Now Enter the capacity of knapsack: ");
    scanf("%d", &wt);
    
    printf("Fractional Knapsack maximum profit: %.2lf\n", knapsack(arr, n, wt));

    return 0;
}

/*
Enter the no of objects: 3
Enter the weight and profit of each object: 
10 60
20 100
30 120
Now Enter the capacity of knapsack: 50
Fractional Knapsack maximum profit: 240
*/