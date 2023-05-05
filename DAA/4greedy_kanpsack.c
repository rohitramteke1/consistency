#include <stdio.h>
#include <stdlib.h> 

#define MAX_N 100
#define MAX_W 1000

typedef struct {
    int weight;
    int value;
} item;

int compare_items(const void* a, const void* b) {
    item* item_a = (item*)a;
    item* item_b = (item*)b;
    double ratio_a = (double)item_a->value / (double)item_a->weight;
    double ratio_b = (double)item_b->value / (double)item_b->weight;
    return ratio_b >= ratio_a;
}

int knapsack(item* items, int n, int max_weight) {
    qsort(items, n, sizeof(item), compare_items);
    int i;
    int total_value = 0;
    int current_weight = 0;
    for (i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= max_weight) {
            current_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            int remaining_weight = max_weight - current_weight;
            double fraction = (double)remaining_weight / (double)items[i].weight;
            total_value += fraction * items[i].value;
            break;
        }
    }
    return total_value;
}

int main() {
    item items[MAX_N];
    int n, max_weight;
    scanf("%d %d", &n, &max_weight);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    int total_value = knapsack(items, n, max_weight);
    printf("Total value: %d\n", total_value);
    return 0;
}
