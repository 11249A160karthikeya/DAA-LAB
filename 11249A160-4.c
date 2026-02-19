#include <stdio.h>

// Structure to store item details
struct Item {
    int profit;
    int weight;
    float ratio;
};

int main() {
    int n, capacity;
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &item[i].profit, &item[i].weight);

        // Avoid division by zero
        if (item[i].weight != 0)
            item[i].ratio = (float)item[i].profit / item[i].weight;
        else
            item[i].ratio = 0;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items in decreasing order of profit/weight ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    printf("\nItems selected:\n");

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (capacity >= item[i].weight) {
            // Take full item
            printf("Item with profit %d and weight %d taken fully\n",
                   item[i].profit, item[i].weight);

            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        } else {
            // Take fraction of item
            float fraction = (float)capacity / item[i].weight;

            printf("Item with profit %d and weight %d taken partially (%.2f fraction)\n",
                   item[i].profit, item[i].weight, fraction);

            totalProfit += item[i].profit * fraction;
            capacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
