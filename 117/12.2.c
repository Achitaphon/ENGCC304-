#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy(int *w, int *v, int n, int wx);

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };

    int *x = KnapsackGreedy(w, v, n, wx);

    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }

    free(x);
    return 0;
}

struct ItemInfo {
    int index;
    int weight;
    int value;
    double ratio;
};

static void swap_item(struct ItemInfo *a, struct ItemInfo *b) {
    struct ItemInfo temp = *a;
    *a = *b;
    *b = temp;
}

static void sort_by_ratio_desc(struct ItemInfo items[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap_item(&items[j], &items[j + 1]);
            }
        }
    }
}

int *KnapsackGreedy(int *w, int *v, int n, int wx) {
    int *selected = (int *)malloc(n * sizeof(int));
    struct ItemInfo *items = (struct ItemInfo *)malloc(n * sizeof(struct ItemInfo));
    int remainingCapacity = wx;

    if (selected == NULL || items == NULL) {
        free(selected);
        free(items);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        selected[i] = 0;

        items[i].index = i;
        items[i].weight = w[i];
        items[i].value = v[i];

        if (w[i] > 0) {
            items[i].ratio = (double)v[i] / (double)w[i];
        } else {
            items[i].ratio = 0.0;
        }
    }

    sort_by_ratio_desc(items, n);

    for (int i = 0; i < n; i++) {
        int idx = items[i].index;

        if (items[i].weight <= remainingCapacity) {
            selected[idx] = 1;
            remainingCapacity -= items[i].weight;
        }
    }

    free(items);
    return selected;
}
