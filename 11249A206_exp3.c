#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting
int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }

// mode: 0 = First Fit, 1 = FF Decreasing, 2 = Best Fit
void solve(int *input_w, int n, int cap, int mode) {
    int bins[100], count = 0, *w = input_w;
    
    // For FF Decreasing (mode 1), create a sorted copy of weights
    if (mode == 1) {
        w = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++) w[i] = input_w[i];
        qsort(w, n, sizeof(int), cmp);
    }

    for (int i = 0; i < n; i++) {
        int best = -1, minSpace = cap + 1;
        for (int j = 0; j < count; j++) {
            if (bins[j] >= w[i]) {
                if (mode != 2) { best = j; break; } // FF & FFD stop immediately
                if (bins[j] - w[i] < minSpace) {    // Best Fit finds tightest spot
                    minSpace = bins[j] - w[i];
                    best = j;
                }
            }
        }
        if (best != -1) bins[best] -= w[i];
        else bins[count++] = cap - w[i]; // Open new bin
    }

    char *labels[] = {"First Fit", "First Fit Decreasing", "Best Fit"};
    printf("%s: Total bins used: %d\n", labels[mode], count);
    
    if (mode == 1) free(w); // Clean up sorted array
}

int main() {
    int n, c, w[100];
    printf("Enter number of items:\n");
    scanf("%d",&n);
    printf ("Enter bin capacity:\n");
    scanf("%d",&c);

    printf("Enter item weights:\n");
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);

    solve(w, n, c, 0); // First Fit
    solve(w, n, c, 1); // First Fit Decreasing
    solve(w, n, c, 2); // Best Fit
    
    return 0;
}
