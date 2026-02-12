#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

int main() {
    int n, capacity;
    struct Item item[100];
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    // FIX: Read both Profit and Weight inside the loop
    printf("Enter profit and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        // Corrected scanf syntax (added comma)
        scanf("%d %d", &item[i].profit, &item[i].weight);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items (Bubble Sort)
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
        if (capacity == 0) break; 

        if (capacity >= item[i].weight) {
            printf("Item with profit %d and weight %d taken fully\n", 
                   item[i].profit, item[i].weight);
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        } else {
            float fraction = (float)capacity / item[i].weight;
            printf("Item with profit %d and weight %d taken partially (%.2f)\n", 
                   item[i].profit, item[i].weight, fraction);
            totalProfit += item[i].profit * fraction;
            break; 
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);
    return 0;
}
